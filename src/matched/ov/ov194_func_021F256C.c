/*
 * function: NAMEIN_GRAPHIC_InitPicker
 * address: 0x021F256C
 * packet: pkt_ov194_021F256C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   NAMEIN_GRAPHIC_GetWord 0x021F4D94 thumb ov194
 *   NAMEIN_GRAPHIC_SymbolGetBox 0x021F299C thumb ov194
 *   NAMEIN_GRAPHIC_SymbolMove 0x021F2BC8 thumb ov194
 *   NAMEIN_GRAPHIC_SymbolGetValue 0x021F2F8C thumb ov194
 *   NAMEIN_GRAPHIC_KanaGetBox 0x021F28FC thumb ov194
 *   NAMEIN_GRAPHIC_KanaMove 0x021F2A88 thumb ov194
 *   NAMEIN_GRAPHIC_ComputeGridValue 0x021F2F68 thumb ov194
 *   d_021F555C 0x021F555C data a4
 */
#include "../include/Obj02530.h"
extern void MI_CpuFill8(void *,unsigned,unsigned);
typedef unsigned int   u32;
extern u32 NAMEIN_GRAPHIC_GetWord(const unsigned char *p, u32 i);
extern int NAMEIN_GRAPHIC_SymbolGetBox(int *,int *);extern void NAMEIN_GRAPHIC_SymbolMove(int *,int *,void *);
extern int NAMEIN_GRAPHIC_SymbolGetValue(int *,int *);extern int NAMEIN_GRAPHIC_KanaGetBox(int *,int *);
typedef unsigned char  u8;
extern void NAMEIN_GRAPHIC_KanaMove(int *p, int *delta, u8 *saved);extern int NAMEIN_GRAPHIC_ComputeGridValue(int *,int *);
extern const unsigned char d_021F555C[];
void NAMEIN_GRAPHIC_InitPicker(char *p, unsigned mode, int index, void *table, u32 a4) {
 int i;
 MI_CpuFill8(p,0,36);((struct Obj02530 *)p)->f0=(void *)NAMEIN_GRAPHIC_GetWord(table,index);
 switch(mode) {
 case 3:
 ((struct Obj02530 *)p)->f20=11;((struct Obj02530 *)p)->f22=4;
 ((struct Obj02530 *)p)->f14=NAMEIN_GRAPHIC_SymbolGetBox;((struct Obj02530 *)p)->f18=NAMEIN_GRAPHIC_SymbolMove;((struct Obj02530 *)p)->f1C=NAMEIN_GRAPHIC_SymbolGetValue;break;
 case 0:case 1:case 2:
 ((struct Obj02530 *)p)->f20=13;((struct Obj02530 *)p)->f22=6;
 ((struct Obj02530 *)p)->f14=NAMEIN_GRAPHIC_KanaGetBox;((struct Obj02530 *)p)->f18=NAMEIN_GRAPHIC_KanaMove;((struct Obj02530 *)p)->f1C=NAMEIN_GRAPHIC_ComputeGridValue;break;
 }
 for(i=0;i<13;i++)*(unsigned char *)(p+4+i)=d_021F555C[i];
}
