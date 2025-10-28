Ce projet est un exercice/devoir en C++ visant à implementer et tester des fonctions de manipulation de chaines de caractères et de memoire. 
Il couvre des opérations comme la copie, la concatenation, la recherche de caracteres, la division de chaînes, la gestion de la memoire, la comparaison alphabetique, la conversion en minuscules et la vérification de chaînes numériques.

# Fonctions implementees et exemples
1. LongueurChaine(const char* chaine):

   calcule le nombre de caracteres dans une chaine

   **exemple**:LongueurChaine("Bonjoure"); le resultat seras : 8

2.CopierChaine(char* destination, const char* source):

copie le contenu de source dans destination.
Elle sert à copier le contenu d’une chaîne de caractères dans une autre.

**exemple**:char copie[50];
CopierChaine(copie, "herve"); la copie devient "herve".

3.ConcatenerChaines(char* destination, const char* source):

Ajoute source à la fin de destination, cet a dire, elle sert a ajouter une chaine de caracteres a la fin d'une autre.

**exemple**:char phrase[100] = "Herve "; //l'espace est la pour que les deux mots ne colle pas
ConcatenerChaines(phrase, "Gabriel");
std::cout << phrase; // Affiche : Hello World!

4.TrouverCaractere(const char* chaine, char caractere):

Cette fonction sert à chercher un caractere precis dans une chaîne de caracteres
Elle retourne un pointeur vers la première position où ce caractère apparaît.


**exemple**:char* position = TrouverCaractere("jacob", 'j'); // position pointe sur 'j'

5. CompterOccurrences(const char* chaine, char caractere):

   Compte combien de fois un caractere apparaît dans la chaîne.

    **exemple**:CompterOccurrences("Banane", 'a'); // Résultat : 2

7. ExtraireSousChaine(char* destination, const char* source, size_t debut, size_t longueur):

   Cette fonction permet d’extraire une portion d’une chaîne de caracteres, à partir d’un indice de départ (debut) et sur une longueur donner (longueur). Elle copie cette portion dans une autre chaîne appelée destination.


    **exemple**:char extrait[20];
ExtraireSousChaine(extrait, "Sangoku", 0, 4); // extrait devient "San", la fin est exclusive.

9. CopierMemoire(void* destination, const void* source, size_t taille):

   Copie un bloc memoire de source vers destination.


   **exemple**:char zone1[10] = "hey";
               char zone2[10];
             CopierMemoire(zone2, zone1, 3); // zone2 contient "hey".
   
11. InitialiserMemoire(void* zone, unsigned char valeur, size_t taille):

    Remplit une zone memoire avec une valeur donnée.


    **exemple**:char zone[10];
   InitialiserMemoire(zone, 'W', 3); // zone contient "WWW"

13. ComparerChaines(const char* chaine1, const char* chaine2):

    Compare deux chaînes caractere par caractere.
    Cette fonction compare deux chaînes de caractères (chaine1 et chaine2) caractère par caractère. Elle retourne :

0 si les deux chaînes sont identiques

 Un nombre positif si chaine1 est plus grande (lexicographiquement)

 Un nombre négatif si chaine1 est plus petite

C’est l’équivalent de la fonction standard strcmp() en C.
    
**exemple**:ComparerChaines("wxy", "wxz"); // Résultat négatif car 'y' < 'z'
ComparerChaines("wxy", "wxy"); // Résultat : 0

    
12. ConvertirMinuscules(char* chaine):

    Transforme toutes les lettres majuscules en minuscules.

     **exemples**:char texte[] = "CHANGER";
ConvertirMinuscules(texte); // texte devient "changer"

14. EstChaineNumerique(const char* chaine):

    Vérifie si une chaîne représente un nombre entier
 * chaine: Chaîne à vérifier (constante)
 * return: true si la chaîne est numérique, false sinon
 * 
 * Vérifie que chaque caractère est un chiffre ('0' à '9')
 * Accepte également un signe '-' au début
 * Rejette les nombres à virgule et autres caractères


    **exemple**:EstChaineNumerique("12345");   // true
EstChaineNumerique("-6789");   // true
EstChaineNumerique("12a45");   // false


    

    














