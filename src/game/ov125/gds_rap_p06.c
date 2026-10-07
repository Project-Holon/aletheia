/*
 * file:     gds_rap_p06.c
 * unit:     yes
 * function: func_021D7BDC, func_021D7C14, func_021D7C48, func_021D7C7C, func_021D7C90, func_021D7CAC
 * address:  0x021D7BDC
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D7BCC 0x021D7BCC arm ov125
 *   func_021D7CC0 0x021D7CC0 arm ov125
 *   d_021D9E40 0x021D9E40 data a4
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0 0x0205A1B0 arm
 *   func_02086028  0x02086028  arm
 *   d_021DA174     0x021DA174  data  a4
 */
#include "../../matched/include/G_Clear.h"

extern unsigned int func_021D7BCC(void);
extern void func_021D7CC0(void);
extern void func_0205A16C(int, int);
extern void func_0205A1B0(int,int,int);
extern void func_02086028(void *);
char *func_021D7BDC(void);
int func_021D7C14(void);
int func_021D7C48(void);
void func_021D7C7C(int a);
void func_021D7C90(int p);
void func_021D7CAC(void);
extern struct Clear d_021D9E40;
extern char d_021DA174[];

char *func_021D7BDC(void) {func_021D7CAC(); if(func_021D7BCC()!=8){func_021D7CC0();return 0;} func_021D7CC0();return *(char **)(((char *)&d_021D9E40)+0x260)+4;}

int func_021D7C14(void){func_021D7CAC();if(func_021D7BCC()!=8){func_021D7CC0();return -1;}else{func_021D7CC0();return *(int*)(((char *)&d_021D9E40)+0x25c);}}

int func_021D7C48(void){func_021D7CAC();if(func_021D7BCC()!=9){func_021D7CC0();return 0;}else{func_021D7CC0();return *(int*)(((char *)&d_021D9E40)+0x250);}}


/*
 * Addresses are Black-image addresses.
 */
void func_021D7C7C(int a)
{
    func_0205A16C(0, a);
}

void func_021D7C90(int p){if(p)func_0205A1B0(0,p,0);}


void func_021D7CAC(void)
{
    func_02086028(d_021DA174);
}
