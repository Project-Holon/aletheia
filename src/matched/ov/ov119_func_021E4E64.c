/*
 * function: func_021E4E64
 * address: 0x021E4E64
 * packet: pkt_ov119_021E4E64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: i before n gives n the earlier spill slot.
 * symbols:
 *   func_021E4DBC 0x021E4DBC thumb ov119
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021E5164 0x021E5164 thumb ov119
 *   func_021E5158 0x021E5158 thumb ov119
 *   func_021E4B00 0x021E4B00 thumb ov119
 *   func_021E4F28 0x021E4F28 thumb ov119
 */
#include "../include/Obj00001.h"
typedef short s16;
extern int func_021E4DBC(char *);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void func_021E5164(int p);
extern int func_021E5158(int);
extern void func_021E4B00(char *, int, int, int, int);
extern void func_021E4F28(char *);
void func_021E4E64(int a, char *p, int b)
{
    int i, n, j;
    n = func_021E4DBC(p);
    if (((struct Obj00001 *)p)->f1080 != n) {
        ((struct Obj00001 *)p)->f1080 = n;
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 5; j++) {
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xbb0), 0);
                *(unsigned char *)(p + i * 5 + j + 0xebc) = 0;
            }
        }
        ((struct Obj00001 *)p)->f1090 = n;
        func_021E5164((int)p);
        for (i = 0; i < 12; i++) {
            func_021E4B00(p, a, n, func_021E5158(((struct Obj00001 *)p)->f1080 + i), b);
            n++;
            if (n >= ((struct Obj00001 *)p)->f634) n = 0;
        }
    }
    func_021E4F28(p);
}
