/*
 * function: POKETRADE_2D_UpdateVisibleColumns
 * address: 0x021E4E64
 * packet: pkt_ov119_021E4E64
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: i before n gives n the earlier spill slot.
 * symbols:
 *   POKETRADE_2D_GetScrollColumn 0x021E4DBC thumb ov119
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_2D_HideAllBoxIcons 0x021E5164 thumb ov119
 *   POKETRADE_2D_WrapIndex12 0x021E5158 thumb ov119
 *   POKETRADE_2D_CreateBoxIcon 0x021E4B00 thumb ov119
 *   POKETRADE_2D_UpdateBoxIconPositions 0x021E4F28 thumb ov119
 */
#include "../include/Obj00001.h"
typedef short s16;
extern int POKETRADE_2D_GetScrollColumn(char *);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void POKETRADE_2D_HideAllBoxIcons(int p);
extern int POKETRADE_2D_WrapIndex12(int);
extern void POKETRADE_2D_CreateBoxIcon(char *, int, int, int, int);
extern void POKETRADE_2D_UpdateBoxIconPositions(char *);
void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b)
{
    int i, n, j;
    n = POKETRADE_2D_GetScrollColumn(p);
    if (((struct Obj00001 *)p)->f1080 != n) {
        ((struct Obj00001 *)p)->f1080 = n;
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 5; j++) {
                CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p + i * 20 + j * 4 + 0xbb0), 0);
                *(unsigned char *)(p + i * 5 + j + 0xebc) = 0;
            }
        }
        ((struct Obj00001 *)p)->f1090 = n;
        POKETRADE_2D_HideAllBoxIcons((int)p);
        for (i = 0; i < 12; i++) {
            POKETRADE_2D_CreateBoxIcon(p, a, n, POKETRADE_2D_WrapIndex12(((struct Obj00001 *)p)->f1080 + i), b);
            n++;
            if (n >= ((struct Obj00001 *)p)->f634) n = 0;
        }
    }
    POKETRADE_2D_UpdateBoxIconPositions(p);
}
