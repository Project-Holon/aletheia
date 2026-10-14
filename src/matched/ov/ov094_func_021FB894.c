/*
 * function: BTLV_EFFVM_CmdFadeClactPalette
 * address:  0x021FB894
 * packet:   pkt_ov094_021FB894
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   BTLV_EFFECT_GetClact  0x021F86F0  thumb  ov094
 *   BTLV_CLACT_RequestPaletteFade  0x02201DB4  thumb  ov094
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;

typedef struct {
    char pad[0xcc];
    int t[92];
    int f23c;
} State;

typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int BTLV_EFFECT_GetClact(void);
extern void BTLV_CLACT_RequestPaletteFade(char *base, int idx, u8 b, u8 c, s8 step, u16 d);

int BTLV_EFFVM_CmdFadeClactPalette(struct Cursor *a, State *s)
{
    int v0 = VM_GetU32(a);
    int v1 = VM_GetU32(a);
    int v2 = VM_GetU32(a);
    int v3 = VM_GetU32(a);
    int v4 = VM_GetU32(a);

    BTLV_CLACT_RequestPaletteFade((char *)BTLV_EFFECT_GetClact(), s->t[v0], v1, v2, v3, v4);
    return s->f23c;
}
