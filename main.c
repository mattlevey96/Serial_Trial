/* 
 * File:   main.c
 * Author: Dan and Matt
 *
 * Created on September 30, 2017, 4:36 PM
 */
#include <htc.h>
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f46k22.h>

/*
 * 
 */
int main(int argc, char** argv) {
    
    SSP1CON1bits.SSPEN = 1; // Set Enable to On
    SSP1CON1bits.CKP = 1; // Set Clock to High
    SSP1CON1bits.SSPM0 = 1; //Set Clock to run on FOSC/16 for SPI
    SSP1CON1bits.SSPM1 = 0;
    SSP1CON1bits.SSPM2 = 0;
    SSP1CON1bits.SSPM3 = 0;
    
    SSP1STATbits.CKE = 0; //Set transmit to occur on rising edge
    SSP1STATbits.SMP = 1; //Set sampling to occur at end of data output time
    
    TRISDbits.RD0 = 0; // Set SPI Clock to Output MAKE SURE TO CHECK WITH WOLF
    TRISDbits.RD1 = 1; // Set SPI Data In to Input
    TRISDbits.RD3 = 1; // Set SPI Slave Select Input to Input
    TRISDbits.RD4 = 0; // Set SPI Data Out to Output
    
    //SSP1BUFbits.SSPBUF - Data Buffer, don't know where we are reading from yet
    
    
    // Initializing USART SND
    // Transmit status and control register
    TXSTA1bits.TX9 = 1; // Enabling 9 bit transmission, 0 would be 8 bits
    TXSTA1bits.TXEN = 1; // Enable transmit
    TXSTA1bits.SYNC = 0; // Asynchronous mode
    //TXSTA1bits.SENDB = 0 // Sync Break transmission completed, if 1, sync break is cleared by hardware on completion
    TXSTA1bits.BRGH = 1; // Sets High Baud Rate Select Bit
    
    // Receive status and control register
    RCSTA1bits.SPEN = 1; // Enables serial port
    
    // Baud Rate Control register  dont think this needs to be set right now actually
    //BAUDCON1bits.
    
   
    return (EXIT_SUCCESS);
}

