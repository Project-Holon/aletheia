/*
 * function: func_021B9B08
 * address: 0x021B9B08
 * packet: pkt_ov217_021B9B08
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9B98 0x021B9B98 thumb ov217
 *   func_021B9C54 0x021B9C54 thumb ov217
 *   func_021B9E44 0x021B9E44 thumb ov217
 *   func_021BA078 0x021BA078 thumb ov217
 *   func_021BA094 0x021BA094 thumb ov217
 *   func_021BA0C4 0x021BA0C4 thumb ov217
 *   func_021B9B80 0x021B9B80 thumb ov217
 *   func_021BA1D4 0x021BA1D4 thumb ov217
 *   func_021BA41C 0x021BA41C thumb ov217
 *   RESEARCH_COMMON_UpdatePaletteAnime 0x021C09D0 thumb ov217
 *   CLACT_DrawSystem 0x0204A600 arm
 *   func_021BA374 0x021BA374 thumb ov217
 *   func_021BA158 0x021BA158 thumb ov217
 * A600's complete body uses globals, no entry r0 reader or forwarder.
 */
#include "../include/Obj00511.h"
extern void func_021B9B98(char *p);
extern void func_021B9C54(char *p);
extern void func_021B9E44(char *p);
extern void func_021BA078(unsigned);
extern void func_021BA094(unsigned);
extern unsigned func_021BA0C4(unsigned);
extern int func_021B9B80(void *);
extern void func_021BA1D4(unsigned);
extern void func_021BA41C(int *);
extern void RESEARCH_COMMON_UpdatePaletteAnime(unsigned);
extern void CLACT_DrawSystem(void);
extern void func_021BA374(void *);
extern void func_021BA158(unsigned);
void func_021B9B08(char *p)
{
    switch (((struct Obj00511 *)p)->f18) {
    case 0:func_021B9B98(p);break;
    case 1:func_021B9C54(p);break;
    case 2:func_021B9E44(p);break;
    case 3:func_021BA078((unsigned)p);break;
    case 4:func_021BA094((unsigned)p);break;
    case 5:func_021BA0C4((unsigned)p);break;
    case 6:return;
    }
    if (func_021B9B80(p)==0) {
        func_021BA1D4((unsigned)p);func_021BA41C((int *)p);
        RESEARCH_COMMON_UpdatePaletteAnime(*(unsigned *)&((struct Obj00511 *)p)->f0);CLACT_DrawSystem();
    }
    func_021BA374(p);func_021BA158((unsigned)p);
}
