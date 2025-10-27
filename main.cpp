#include <iostream>

// Prototypes des fonctions
size_t LongueurChaine(const char* chaine);
void CopierChaine(char* destination, const char* source);
void ConcatenerChaines(char* destination, const char* source);
char* TrouverCaractere(const char* chaine, char caractere);
size_t CompterOccurrences(const char* chaine, char caractere);
void CopierMemoire(void* destination, const void* source, size_t taille);
void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille);
void ExtraireSousChaine(char* destination, const char* source, 
                       size_t debut, size_t longueur);
size_t DiviserChaine(const char* chaine, char separateur, 
                    char resultat[][100], size_t max_resultats);
int ComparerChaines(const char* chaine1, const char* chaine2);
void ConvertirMinuscules(char* chaine);
bool EstChaineNumerique(const char* chaine);

int main() {
    std::cout << "=== TEST DES FONCTIONS DE MANIPULATION DE CHAINES STYLE C ===" << std::endl;
    std::cout << "Compilé avec C++ et CLang++" << std::endl << std::endl;
    
    // Test 1: Longueur de chaîne
    char message[] = "Bonjour le monde";
    std::cout << "1. Longueur de '" << message << "': " << LongueurChaine(message) << std::endl;
    
    // Test 2: Copie de chaîne
    char copie[50];
    CopierChaine(copie, message);
    std::cout << "2. Copie: '" << copie << "'" << std::endl;
    
    // Test 3: Concaténation
    char salutation[100] = "Hello ";
    ConcatenerChaines(salutation, "World!");
    std::cout << "3. Concaténation: '" << salutation << "'" << std::endl;
    
    // Test 4: Recherche de caractère
    char* position = TrouverCaractere(message, 'j');
    if (position != nullptr) {
        std::cout << "4. Caractère 'j' trouvé à la position: " << (position - message) << std::endl;
    } else {
        std::cout << "4. Caractère 'j' non trouvé" << std::endl;
    }
    
    // Test 5: Comptage d'occurrences
    std::cout << "5. Occurrences de 'o' dans '" << message << "': " 
              << CompterOccurrences(message, 'o') << std::endl;
    
    // Test 6: Extraction de sous-chaîne
    char sous_chaine[20];
    ExtraireSousChaine(sous_chaine, message, 3, 5);
    std::cout << "6. Sous-chaîne (pos 3, longueur 5): '" << sous_chaine << "'" << std::endl;
    
    // Test 7: Division de chaîne
    char phrase[] = "pomme,orange,banane,kiwi";
    char fruits[10][100];
    size_t nb_fruits = DiviserChaine(phrase, ',', fruits, 10);
    
    std::cout << "7. Division de '" << phrase << "':" << std::endl;
    for (size_t i = 0; i < nb_fruits; i++) {
        std::cout << "   [" << i << "] " << fruits[i] << std::endl;
    }
    
    // Test 8: Fonctions mémoire
    char zone1[10] = "ABCDEFGHI";
    char zone2[10];
    CopierMemoire(zone2, zone1, 5);
    zone2[5] = '\0';
    std::cout << "8. Copie mémoire (5 octets): '" << zone2 << "'" << std::endl;
    
    char zone3[10];
    InitialiserMemoire(zone3, 'X', 5);
    zone3[5] = '\0';
    std::cout << "9. Initialisation mémoire: '" << zone3 << "'" << std::endl;
    
    // Test 10: Comparaison de chaînes
    char chaineA[] = "apple";
    char chaineB[] = "banana";
    int resultat_comparaison = ComparerChaines(chaineA, chaineB);
    std::cout << "10. Comparaison '" << chaineA << "' vs '" << chaineB << "': " 
              << resultat_comparaison << std::endl;
    
    // Test 11: Conversion minuscules
    char mixte[] = "Hello World!";
    std::cout << "11. Avant conversion: '" << mixte << "'" << std::endl;
    ConvertirMinuscules(mixte);
    std::cout << "    Après conversion: '" << mixte << "'" << std::endl;
    
    // Test 12: Vérification numérique
    char numerique[] = "12345";
    char non_numerique[] = "12a45";
    std::cout << "12. '" << numerique << "' est numérique: " 
              << (EstChaineNumerique(numerique) ? "OUI" : "NON") << std::endl;
    std::cout << "    '" << non_numerique << "' est numérique: " 
              << (EstChaineNumerique(non_numerique) ? "OUI" : "NON") << std::endl;
    
    return 0;
}
size_t LongueurChaine(const char* chaine) {

    const char* debut = chaine;
    while (*chaine != '\0') {
    chaine++;
    }
    return chaine - debut;
}


void CopierChaine(char* destination, const char* source) {

    while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0'; // Fin de chaîne
}


void ConcatenerChaines(char* destination, const char* source) {


    // 1. Avancer jusqu'à la fin de destination
    while (*destination != '\0') {
destination++;
    }
  while (*source != '\0') {
        *destination = *source;
        destination++;
        source++;
    }

    // 3. Terminer avec '\0'
    *destination = '\0';
}


char* TrouverCaractere(const char* chaine, char caractere) {

    while (*chaine != '\0') {
        if (*chaine == caractere) {

            return (char*)chaine; 
        }
        chaine++;
    }
    return nullptr; // Caractère non trouvé
}


void CopierMemoire(void* destination, const void* source, size_t taille) {
    unsigned char* dest = (unsigned char*)destination;
    const unsigned char* src = (const unsigned char*)source;

    for (size_t i = 0; i < taille; i++) {
        dest[i] = src[i];//On parcourt chaque octet de 0 à taille - 1.

//On copie src[i] dans dest[i].
    }
}

size_t CompterOccurrences(const char* chaine, char caractere) {
    size_t compteur = 0;

    while (*chaine != '\0') {
//On lit chaque caractere avec *chaine.

//Tant qu’on n’a pas atteint la fin ('\0'), on continue.


        if (*chaine == caractere) {
            compteur++;//i le caractère actuel est celui qu’on cherche, on incremente.
        }
        chaine++;
    }

    return compteur;
}

void InitialiserMemoire(void* zone, unsigned char valeur, size_t taille) {
    unsigned char* ptr = (unsigned char*)zone;

    //On parcourt chaque position de 0 à taille - 1.
//On écrit valeur dans chaqe octet.
    for (size_t i = 0; i < taille; i++) {
        ptr[i] = valeur;
    }
}

void ExtraireSousChaine(char* destination, const char* source, 
                        size_t debut, size_t longueur) {
    size_t i = 0;

    size_t tailleSource = 0;
    while (source[tailleSource] != '\0') {
        tailleSource++;
    }

    if (debut >= tailleSource) {
        destination[0] = '\0'; // Rien à extraire
        return;
    }

    // Extraction avec protection contre depasement
    while (i < longueur && source[debut + i] != '\0') {
        destination[i] = source[debut + i];
        i++;
    }

    // Terminer la sous-chaîne
    destination[i] = '\0';
}

size_t DiviserChaine(const char* chaine, char separateur, 
                     char resultat[][100], size_t max_resultats) {
    size_t compteur_resultats = 0;
    size_t index_courant = 0;

    for (size_t i = 0; chaine[i] != '\0'; i++) {
        if (chaine[i] == separateur) {
            // Ignorer les séparateurs consécutifs
            if (index_courant > 0 && compteur_resultats < max_resultats) {
                resultat[compteur_resultats][index_courant] = '\0'; // Fin de sous-chaîne
                compteur_resultats++;
                index_courant = 0;
            }
        } else {
            if (compteur_resultats < max_resultats && index_courant < 99) {
                resultat[compteur_resultats][index_courant] = chaine[i];
                index_courant++;
            }
        }
    }

    // Ajouter la derniere soushaîne si elle existe
    if (index_courant > 0 && compteur_resultats < max_resultats) {
        resultat[compteur_resultats][index_courant] = '\0';
        compteur_resultats++;
    }

    return compteur_resultats;
}

int ComparerChaines(const char* chaine1, const char* chaine2) {
    while (*chaine1 != '\0' && *chaine2 != '\0') {
        if (*chaine1 != *chaine2) {
            return *chaine1 - *chaine2;
        }
        chaine1++;
        chaine2++;
    }

    // Si les deux chaînes se terminent en même temps
    if (*chaine1 == '\0' && *chaine2 == '\0') {
        return 0;
    }

    // Si l'un est plus longe que l'autre
    return *chaine1 - *chaine2;
}

void ConvertirMinuscules(char* chaine) {
    while (*chaine != '\0') {
        if (*chaine >= 'A' && *chaine <= 'Z') {
            *chaine = *chaine + 32;
        }
        chaine++;
    }
}
bool EstChaineNumerique(const char* chaine) {
    // Étape 1 : Vérifier le signe négatif
    if (*chaine == '-') {
        chaine++; // Avancer d'une position
    }

    // Étape 2 : Vérifier qu'il y a au moins un chiffre
    if (*chaine == '\0') {
        return false; // Cas où la chaîne est juste "-"
    }

    // Étape 3 : Parcourir chaque caractère
    while (*chaine != '\0') {
        if (*chaine < '0' || *chaine > '9') {
            return false; // Caractère non numérique
        }
        chaine++;
    }

    return true; // Tous les caractères sont valides
}




