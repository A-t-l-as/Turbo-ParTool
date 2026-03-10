//stale uzywane przy dynamicznym tworzeniu obiektow
//opis:
//dla klas abstrakcyjnych nie nalezy definiowac stalych
//
//pierwszy bajt zawiera podstawowe klasy dziedziczace z CSObject - moze byc
//ich 8
//kolejne klasy dziedziczace z bazowych definiujemy na razie na 4 bitach 
//w razie potrzeby trzeba bedzie inaczej pakowac bity

//uwaga: poniewaz zaczelo brakowac numerkow wiec zmiana - teraz wszystkie poziomy klas sa
//na 8 bitach

//wyjatek (w stosunku do tych 8 bitow) CScriptedActive klasy z niej dziedziczace sa pakowane aby sie zmiescic


#define VIRTUAL                                 0x80000000

#define OTHER                                   0x00000002
//||*****************************************************************
//dla klas "dziedziczacych" z OTHER nie robimy hierarchii tylko nadajemy im kolejne bity
////derived from OTHER
#define LOCALPLAYER                             0x00000102      //derived from OTHER
#define PLAYER                                  0x00000202      //derived from OTHER
#define GAMEPLAYER                              0x00000402      //derived from OTHER
#define AIPLAYER                                0x00000802      //derived from OTHER
#define AIGAMEPLAYER                            0x00001002      //derived from OTHER
#define AIWORLD									0x00002002		//derived from OTHER
#define WORLD									0x00004002		//derived from OTHER
#define COMMAND									0x00008002		//derived from OTHER
#define MULTIEXPLOSION                          0x00010002      //derived from OTHER
#define EARTHCVM	                            0x00020002      //derived from OTHER
//*******************************************************************    





//nie mozna zajac 0x00200101 - tam (8) jest bit MOVEABLE
#define GENERIC                                 0x00000001
//||*****************************************************************
#define STOREABLE                               0x00000011      //derived from GENERIC
#define EQUIPMENT                               0x00000021      //derived from GENERIC
//*******************************************************************
////derived from STOREABLE
#define DYNAMIC                                 0x00000411      //derived from STOREABLE
#define ACTIVE                                  0x00000111      //derived from STOREABLE
#define PASSIVE                                 0x00000211      //derived from STOREABLE
#define MINE                                    0x00000811      //derived from STOREABLE
#define VISIBLEFAKE                             0x00001011      //derived from STOREABLE
//*******************************************************************
//////derived from EQUIPMENT
#define CANNON                                  0x00000121      //derived from EQUIPMENT
#define LOOKROUNDEQUIPMENT                      0x00000221      //derived from EQUIPMENT
#define SPECIALEQUIPMENT                        0x00000421      //derived from EQUIPMENT
#define MAGICEQUIPMENT                          0x00000821      //derived from EQUIPMENT
#define LOOKROUNDEQUIPMENTEFFECT                0x00001021      //derived from EQUIPMENT
//*******************************************************************
//////derived from SPECIALEQUIPMENT
#define SPECIALEQUIPMENTEX                      0x00010421      //derived from SPECIALEQUIPMENT
//*******************************************************************
//////derived from DYNAMIC
#define MISSILE                                 0x00010411      //derived from DYNAMIC
#define EXPLOSION                               0x00020411      //derived from DYNAMIC
#define FLYINGWASTE                             0x00040411      //derived from DYNAMIC
#define SMOKE                                   0x00080411      //derived from DYNAMIC
//********************************************************************
////derived from ACTIVE
#define BUILDING                                0x00010111      //derived from ACTIVE
#define AIPLATOON                               0x00020111      //derived from ACTIVE
#define VERTICALVEHICLE                         0x00040111      //derived from ACTIVE
#define STARTINGPOSITIONMARK                    0x00080111      //derived from ACTIVE
#define SCRIPTEDACTIVE                          0x00100111      //derived from ACTIVE
//********************************************************************
////derived from PASSIVE
#define BUILDPASSIVE                            0x00010211      //derived from PASSIVE
#define ANIMATEDPASSIVE                         0x00040211      //derived from PASSIVE
//********************************************************************
////derived from ANIMATEDPASSIVE
#define SPECIALPASSIVE                          0x01040211      //derived from ANIMATEDPASSIVE
#define GHOSTPASSIVE                            0x02040211      //derived from ANIMATEDPASSIVE
#define TRANSIENTPASSIVE                        0x04040211      //derived from ANIMATEDPASSIVE
#define ANIMALPASSIVE                           0x08040211      //derived from ANIMATEDPASSIVE
//********************************************************************
////derived from TRANSIENTPASSIVE
#define ARTEFACT                                0x14040211      //derived from TRANSIENTPASSIVE
#define TRAP                                    0x44040211      //derived from TRANSIENTPASSIVE
//********************************************************************
////derived from ARTEFACT
#define EQUIPMENTARTEFACT                       0x34040211      //derived from ARTEFACT
//********************************************************************
////derived from EXPLOSION
#define EXPLOSIONEX                             0x01020411      //derived from EXPLOSION
//********************************************************************
////derived from SMOKE
#define SMOKEFIRE                               0x01080411      //derived from SMOKE
//********************************************************************
////derived from VERTICALVEHICLE
#define VERTICALVEHICLEBOMBER                   0x01040111      //derived from VERTICALVEHICLE
#define VERTICALVEHICLESPY                      0x02040111      //derived from VERTICALVEHICLE
//********************************************************************
////derived from SCRIPTEDACTIVE (na jednym bajcie ze SCRIPTEDACTIVE)
#define MOVEABLE                                0x00300111      //derived from SCRIPTEDACTIVE (na jednym bajcie ze SCRIPTEDACTIVE)
//********************************************************************
////derived from MOVEABLE
#define REPAIRER                                0x01300111      //derived from MOVEABLE
#define HARVESTER                               0x02300111      //derived from MOVEABLE
#define RPGUNIT                                 0x04300111      //derived from MOVEABLE
#define SHOPUNIT                                0x08300111      //derived from MOVEABLE
//*******************************************************************
////derived from REPAIRER
#define BUILDER                                 0x11300111      //derived from REPAIRER
//*******************************************************************


//MOVEABLE i klasy z niego dziedziczace upychamy na kolejnych bitach zeby sie jakos zmiescic

//po zmianie tego pliku nalezy go skopiowac do katalogu z parametrami
//i przed uzyciem wygenerowac nowy plik parametrow

//powyzszych stalych nie nalezy uzywac bezposrednio ale 
//przy define DECLARE_DYNCREATE, a przy sprawdzaniu czy obiekt jest danej klasy
//nalezy uzywac makra IS_KIND_OF a przy porownywaniu identyfikatora
//IS_ID_KIND_OF
