/*
 * file:     unit_021BC240.c
 * unit:     yes
 * function: func_021BC240, func_021BC274, func_021BC288, func_021BC298, func_021BC2B0, func_021BC2BC, func_021BC2E4, func_021BC2FC, func_021BC308, func_021BC370, func_021BC380
 * address:  0x021BC240
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_021BCC58 0x021BCC58 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020419E4 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02005624 0x02005624 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   d_021BE7D4 0x021BE7D4 data a4
 */
#include "../../matched/include/Obj00123.h"
#include "../../matched/include/Obj25533.h"
#include "../../matched/include/Obj25534.h"
#include "../../matched/include/Obj25535.h"
#include "../../matched/include/Obj25536.h"

struct Obj0203159C;
struct S020315D4;
struct Node;
struct S02021D50;
struct DispVram;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *,unsigned,unsigned);
extern void MI_CpuFill8(void *,int,int);
extern int func_021BCC58(char *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *);
extern void func_020419E4(void),CLACT_VBlankSystem(void);
extern void PALANM_TransferPalettes(struct S02021D50 *);
extern void *func_02005624(unsigned,unsigned,unsigned);
extern void BG_SYS_SetVramBanks(const struct DispVram *);
int func_021BC240(struct Obj0203159C *p,int unused,unsigned v);
int func_021BC274(int a, int b, int c, int d);
int func_021BC288(void *p);
void func_021BC298(char *p);
void func_021BC2B0(char *p);
void func_021BC2BC(void *unused,char *p);
void func_021BC2E4(char *p);
void func_021BC2FC(char *p);
void func_021BC308(void);
void func_021BC370(void);
void *func_021BC380(void);
extern const struct DispVram d_021BE7D4;





int func_021BC240(struct Obj0203159C *p,int unused,unsigned v){unsigned *q;GFL_HEAP_CreateChildHeap(1,107,0x60000);q=PROCSYS_AllocProcWork(p,0xc44,107);MI_CpuFill8(q,0,0xc44);*q=v;return 1;}






int func_021BC274(int a, int b, int c, int d)
{
    if (func_021BCC58((char *)d) == 0)
        return 1;
    return 0;
}






int func_021BC288(void *p)
{
    func_020315D4(p);
    func_020306F0(0x6b);
    return 1;
}





void func_021BC298(char *p){((struct Obj00123 *)p)->f4=func_020056A0((unsigned)func_021BC2BC,(unsigned)p,0);}





void func_021BC2B0(char *p){func_02030EAC(*(struct Node * *)&((struct Obj25533 *)p)->f4);}





/*
 * lever: enum-typed DTCM base preserves the base-first two-pool address; constant addition folds and enum offset reverses pool/register roles.
 * volatile: hardware interrupt check flag at 02FE3FF8 read and written by 021BC2D4/021BC2D8.
 */
void func_021BC2BC(void *unused,char *p){enum Base { DTCM_BASE=0x02fe0000 } base;func_020419E4();CLACT_VBlankSystem();PALANM_TransferPalettes(*(struct S02021D50 * *)&((struct Obj25534 *)p)->fC);base=DTCM_BASE;*(volatile unsigned *)&((struct Obj25535 *)base)->f3FF8|=1;}





void func_021BC2E4(char *p){((struct Obj00123 *)p)->f8=func_02005624((unsigned)func_021BC308,(unsigned)p,0);}





void func_021BC2FC(char *p)
{
    func_02030EAC(((struct Obj25536 *)p)->f8);
}



/*
 * volatile: VCOUNT read at 021BC30A; BLDALPHA writes at 021BC314, 021BC320, 021BC32C, 021BC338, 021BC344, 021BC34A
 */
void func_021BC308(void)
{
    int v = *(volatile u16 *)0x04000006;
    if (v >= 168) {
        *(volatile u16 *)0x04001052 = 0x050B;
        return;
    }
    if (v >= 144) {
        *(volatile u16 *)0x04001052 = 0x060A;
        return;
    }
    if (v >= 120) {
        *(volatile u16 *)0x04001052 = 0x0709;
        return;
    }
    if (v >= 96) {
        *(volatile u16 *)0x04001052 = 0x0808;
        return;
    }
    if (v >= 72) {
        *(volatile u16 *)0x04001052 = 0x0A06;
        return;
    }
    *(volatile u16 *)0x04001052 = 0x0C04;
}


void func_021BC370(void){BG_SYS_SetVramBanks(&d_021BE7D4);}

void *func_021BC380(void){return (void *)&d_021BE7D4;}
