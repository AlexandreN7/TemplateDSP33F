/*
* Template dsPIC33F
* Compiler : Microchip xC16
* µC : 33FJ64MC802
* Juillet 2012
*    ____________      _           _
*   |___  /| ___ \    | |         | |
*      / / | |_/ /___ | |__   ___ | |_
*     / /  |    // _ \| '_ \ / _ \| __|
*    / /   | |\ \ (_) | |_) | (_) | |_
*   /_/    |_| \_\___/|____/ \___/'\__|
*			      7robot.fr
*/

/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#include <p33Fxxxx.h>      /* Includes device header file                     */
#include <stdint.h>        /* Includes uint16_t definition                    */
#include <stdbool.h>       /* Includes true/false definition                  */
#include "header.h"        /* Function / Parameters                           */
#include "qei.h"


/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

void ConfigureOscillator(void)
{

    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBDbits.PLLDIV = 150; // M=69152
    CLKDIVbits.PLLPOST = 0; // N1=2
    CLKDIVbits.PLLPRE  = 5; // N2=7
    // Fosc = M/(N1.N2)*Fin
    // FCY = FOSC /2
    // le pic tourne à 80MHZ
}

void InitApp(void)
{

    //pin de la0 LED en sortie
    _TRISA0 = 0;
    _TRISA2 = 0;
    //Si on a un interrupteur sur la pin RB5 (par exemple), on la met en entrée
    _TRISB5 = 1;
    //Et on active la pullup qui va bien (registres CNPU1 et CNPU2)
    _CN27PUE = 1;
    _UARTEN =1;

}