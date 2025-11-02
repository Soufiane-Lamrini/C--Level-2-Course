#include <iostream>


using namespace std;
enum enOpetrationType { Som = 1, Sous = 2, Mul = 3, Div = 4, MixOp = 5 };
enum enNiveauQuestion { Fac = 1, Med = 2, Har = 3,  Mix = 4};
int RandomNombre(int from, int to)
{
    return rand() % (to - from + 1) + from;
}
enOpetrationType RandomOperateurType()
{
    int Op = RandomNombre(1, 4);
    return (enOpetrationType)Op;
}
struct stQuestion
{
    int Number1 = 0;
    int Number2 = 0;
    enOpetrationType TypeOperateur;
    enNiveauQuestion NiveauQuestion;
    int CorrectReponse = 0;
    int ReponseJoueur;
    bool ReponseResultat = false;
};
struct stQuiz{
    stQuestion QuestionList[100];
    short NombreQuestion;
    enNiveauQuestion NiveauQuestion;
    enOpetrationType OpType;
    short NombreFalseQuestion = 0;
    short NombreVraiQuestion = 0;
    bool estPasser = false;
};
short LireCombienQuestion()
{
    short NumberQuestion;
    do
    {
        cout << "Combien de question que tu veux repondre entre 1 et 10m?";
        cin >> NumberQuestion;
    } while (NumberQuestion < 1 || NumberQuestion>10);
    return NumberQuestion;
}
enNiveauQuestion LireQuestionNiveau()
{
    short QuestionNiveau = 0;
    do
    {
        cout << "Entrez le niveau des questions que tu veux? \n[1] Facile\n[2] Medium\n[3] Hard \n[4] Mix ";
        cin >> QuestionNiveau;
    } while (QuestionNiveau > 4 || QuestionNiveau < 1);
    return (enNiveauQuestion)QuestionNiveau;
}
enOpetrationType LireTypeOperateur()
{
    short OperateurType = 0;
    do
    {
        cout << "Quel type d'operateur tu veux?\n[1] Somme\n[2] Soustraction\n[3] Multiplication\n[4] Division\n[5] Mix";
        cin >> OperateurType;
    } while (OperateurType > 5 || OperateurType < 1);
    return (enOpetrationType)OperateurType;
}

string QuestionNiveau(enNiveauQuestion QuestionNiveau)
{
    string arrQuestionLevelText[4] = { "Easy","Medium","Hard","Mixed" };
    return arrQuestionLevelText[QuestionNiveau - 1];
}
string GetOpTypeSymbol(enOpetrationType OpType)
{
    switch (OpType)
    {
    case enOpetrationType::Som:
        return "+";
    case enOpetrationType::Sous:
        return "-";
    case enOpetrationType::Mul:
        return "x";
    case enOpetrationType::Div:
        return "/";
    default:
        return "Mix";
    }
}

int CalculBonneReponse(int Nombre1, int Nombre2, enOpetrationType OpType)
{
    switch (OpType)
    {
    case enOpetrationType::Som:
        return Nombre1 + Nombre2;
    case enOpetrationType::Sous:
        return Nombre1 - Nombre2;
    case enOpetrationType::Mul:
        return Nombre1 * Nombre2;
    case enOpetrationType::Div:
        return (Nombre2 != 0) ? (Nombre1 / Nombre2) : 0;  
    default:
        return Nombre1 + Nombre2;
    }
}

stQuestion GenerQuestion(enNiveauQuestion QuestionNiveau, enOpetrationType TypeOperateur)
{
    stQuestion Question;
    if (QuestionNiveau == enNiveauQuestion::Mix)
    {
        QuestionNiveau = (enNiveauQuestion)RandomNombre(1, 3);
    }
    if (TypeOperateur == enOpetrationType::MixOp)
    {
        TypeOperateur = RandomOperateurType();
    }
    Question.TypeOperateur = TypeOperateur;
    switch (QuestionNiveau)
    {
    case enNiveauQuestion::Fac:
        Question.Number1 = RandomNombre(1, 10);
        Question.Number2 = RandomNombre(1, 10);

        Question.CorrectReponse = CalculBonneReponse(Question.Number1, Question.Number2, Question.TypeOperateur);
        Question.NiveauQuestion = QuestionNiveau;
        return Question;
    case enNiveauQuestion::Med:
        Question.Number1 = RandomNombre(10, 50);
        Question.Number2 = RandomNombre(10, 50);

        Question.CorrectReponse = CalculBonneReponse(Question.Number1, Question.Number2, Question.TypeOperateur);
        Question.NiveauQuestion = QuestionNiveau;
        return Question;

    case enNiveauQuestion::Har:
        Question.Number1 = RandomNombre(50, 100);
        Question.Number2 = RandomNombre(50, 100);

        Question.CorrectReponse = CalculBonneReponse(Question.Number1, Question.Number2, Question.TypeOperateur);
        Question.NiveauQuestion = QuestionNiveau;
        return Question;

    }
    return Question;
}
void GenererQuestionQuiz(stQuiz& Quiz)
{
    for (short Question = 0; Question < Quiz.NombreQuestion; Question++)
    {
        Quiz.QuestionList[Question] = GenerQuestion(Quiz.NiveauQuestion, Quiz.OpType);
    }
}
void AfficherQuestion(stQuiz& Quiz, short QuestionNumber)
{
    cout << "\n";
    cout << "Question [ " << QuestionNumber + 1 << "/" << Quiz.NombreQuestion << " ]\n\n";
    cout << Quiz.QuestionList[QuestionNumber].Number1 << endl;
    cout << Quiz.QuestionList[QuestionNumber].Number2 << " ";
    cout << GetOpTypeSymbol(Quiz.QuestionList[QuestionNumber].TypeOperateur);
    cout << "\n____________" << endl;
}
void SetScreenColor(bool Right)
{
    if (Right)
        system("color 2F"); 
    else
    {
        system("color 4F"); 
        cout << "\a"; 
    }
}
int LireReponseJoueur()
{
    int ReponseJoueur = 0;
    cin >> ReponseJoueur;
    return ReponseJoueur;
}
void CorrigerQuestion(stQuiz& Quiz, short QuestionNumber)
{
    if (Quiz.QuestionList[QuestionNumber].ReponseJoueur != Quiz.QuestionList[QuestionNumber].CorrectReponse)
    {
        Quiz.QuestionList[QuestionNumber].ReponseResultat = false;
        Quiz.NombreFalseQuestion++;

        cout << "False Question :-(\n";
        cout << "Vrai reponse est: ";
        cout << Quiz.QuestionList[QuestionNumber].CorrectReponse;
        cout << endl;
    }
    else
    {
        Quiz.QuestionList[QuestionNumber].ReponseResultat = true;
        Quiz.NombreVraiQuestion++;

        cout << "Vrai reponse, Bravo! :-)\n";
    }
    cout << endl;
    SetScreenColor(Quiz.QuestionList[QuestionNumber].ReponseResultat);
}
void DemandeEtCourigerQuestion(stQuiz& Quiz)
{
    for (short QuestionNumber = 0; QuestionNumber < Quiz.NombreQuestion; QuestionNumber++)
    {
        AfficherQuestion(Quiz, QuestionNumber);
        Quiz.QuestionList[QuestionNumber].ReponseJoueur = LireReponseJoueur();
        CorrigerQuestion(Quiz, QuestionNumber);
    }
    Quiz.estPasser = (Quiz.NombreVraiQuestion >= Quiz.NombreFalseQuestion);
}
string FinalResultats(bool estPass)
{
    if (estPass)
    {
        return "Vous aves passez le quiz avec succes";
    }
    else
    {
        return "Vous aves echoue :-(";
    }
}
void afficherFinalResultats(stQuiz Quiz)
{
    cout << "\n";
    cout << "_____________________\n\n";
    cout << " Final resultats " << FinalResultats(Quiz.estPasser);
    cout << "\n______________________\n\n";

    cout << "Nombre des questions: " << Quiz.NombreQuestion << endl;
    cout << "Questions Niveau est: " << QuestionNiveau(Quiz.NiveauQuestion) << endl;
    cout << "Operateur type est: " << GetOpTypeSymbol(Quiz.OpType) << endl;
    cout << "Nombre des questions vrai est " << Quiz.NombreVraiQuestion << endl;
    cout << "Nombre des questions false" << Quiz.NombreFalseQuestion << endl;
    cout << "_______________________________\n";

}
void playQuiz()
{
    stQuiz Quiz;
    Quiz.NombreQuestion = LireCombienQuestion();
    Quiz.NiveauQuestion = LireQuestionNiveau();
    Quiz.OpType = LireTypeOperateur();

    GenererQuestionQuiz(Quiz);
    DemandeEtCourigerQuestion(Quiz);
    afficherFinalResultats(Quiz);
}
void resetScreen()
{
    system("cls");
    system("Color 0F");
}
void startQuiz()
{
    char rejouer = 'o';
    do
    {
        resetScreen();
        playQuiz();
        cout << endl << "Tu veux rejoeur un autre fois? O/N";
        cin >> rejouer;
    } while (rejouer == 'o' || rejouer == 'O');
}
int main()
{
    srand((unsigned)time(NULL));

    startQuiz();

}
