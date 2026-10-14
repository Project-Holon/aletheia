/*
 * function: POKETRADE_SAVE_PrintStatValues
 * address: 0x021E1880
 * packet: pkt_ov119_021E1880
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E7984 0x021E7984 data a4
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 */
#include "../include/Obj00001.h"
typedef short s16;
typedef struct { int v[5]; } T5;
extern const T5 d_021E7984;
typedef unsigned int   u32;
struct MsgBank;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
void POKETRADE_SAVE_PrintStatValues(int a, int b, int c, int d, char *p)
{
    int i = 0;
    T5 t = d_021E7984;
    for (; i < 5; i++) {
        MSGDATA_ReadString(((struct Obj00001 *)p)->f720, 0x28, ((struct Obj00001 *)p)->f734);
        func_0201EFA4(((struct Obj00001 *)p)->f724, 0, POKE_TOOL_GetPartyValue((void *)a, t.v[i], 0), 3, 1, 1);
        func_0201F250(((struct Obj00001 *)p)->f724, ((struct Obj00001 *)p)->f730, ((struct Obj00001 *)p)->f734);
        PRINTSYS_Print(BMP_WIN_GetBmp((struct Descriptor *)b), (s16)c, (s16)(d + i * 16), ((struct Obj00001 *)p)->f730, ((struct Obj00001 *)p)->f728);
    }
}
