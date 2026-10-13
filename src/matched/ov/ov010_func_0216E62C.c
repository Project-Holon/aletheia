/*
 * function: FLDMMDL_ApplyBurmyFormForPlace
 * address:  0x0216E62C
 * packet:   pkt_ov010_0216E62C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200CA1C  0x0200CA1C  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   d_02172554  0x02172554  data  ov010  a2
 *   d_02172556  0x02172556  data  ov010  a2
 */

typedef unsigned short u16;

struct Blk37;
extern void *func_0200CA1C(void *a);
extern unsigned int POKE_TOOL_GetPartyValue(void *a, unsigned int b, unsigned int c);
typedef unsigned int   u32;
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern u16 d_02172554[][2];
extern u16 d_02172556[][2];

void FLDMMDL_ApplyBurmyFormForPlace(int a, int p, int id)
{
    int h;
    int t;
    int i;

    h = (int)func_0200CA1C((void *)a);
    t = POKE_TOOL_GetPartyValue((void *)p, 5, 0);
    for (i = 0; i < 25; i++) {
        if (id == d_02172554[i][0]) {
            int v = d_02172556[i][0];
            if (t == 0x19c) {
                POKE_TOOL_ChangeForm((void *)p, (u16)v);
                func_0200CFA0((struct Blk37 *)h, (void *)p);
            }
            return;
        }
    }
}
