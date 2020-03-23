#ifndef STRUCTURES_H
# define STRUCTURES_H
# define BAS 2
# define HAUT 2
# define GAUCHE 2
# define DROITE 2

char* intersections[BAS][HAUT][GAUCHE][DROITE] = 
   { {{{" ","╶"},{"╴","─"}},{{"╵","└"},{"┘","┴"}}},
     {{{"╷","┌"},{"┐","┬"}},{{"│","├"},{"┤","┼"}}} };

#endif
