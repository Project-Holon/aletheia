/*
 * function: func_021DD6E8
 * address:  0x021DD6E8
 * packet:   pkt_021DD6E8
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_ChangeBoxForm  0x020179B8  thumb
 *   POKE_TOOL_CreateFromBoxParam  0x0201747C  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned int u32;

struct Blk37;
extern int POKE_TOOL_ChangeBoxForm(int a0, int a1);
struct Mon;
extern void *POKE_TOOL_CreateFromBoxParam(struct Mon *p, u32 heap);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *p, void *m);
extern u32 func_020307B0(void *p);

void func_021DD6E8(void **pp, void *a, u32 b)
{
    void *r;

    POKE_TOOL_ChangeBoxForm((int)a, b);
    r = POKE_TOOL_CreateFromBoxParam(a, 0x4c);
    ZUKAN_SAVE_RegisterSeen(ZUKAN_SAVE_GetFromGameData((void *)(*(u32 *)*pp)), r);
    func_020307B0(r);
}
