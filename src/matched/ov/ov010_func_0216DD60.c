/*
 * function: FLDMMDL_SysSearchGridPosList
 * address:  0x0216DD60
 * packet:   pkt_ov010_0216DD60
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Collects up to 16 matching objects into a 0x44-byte result block
 * (count word, then the pointers).
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_MOVE_IsGridInObjectRect  0x02163C04  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int n;
    u8 *e[16];
} List;

extern void func_02082BCC(void *p, u32 v, u32 n);
struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_MOVE_IsGridInObjectRect(int a, int x, int y, int flag);

int FLDMMDL_SysSearchGridPosList(u32 x, u32 b, u32 c, u32 d, List *out)
{
    int n;
    u8 *o;

    n = 0;
    func_02082BCC(out, 0, 0x44);
    while (FLDMMDL_SysSearchUseMmdl((struct Ctx *)x, (struct Rec **)(&o), (u32 *)(&n)) == 1) {
        if (FLDMMDL_MOVE_IsGridInObjectRect((int)o, b, c, d) == 1) {
            int i = out->n++;
            out->e[i] = o;
            if (out->n >= 16)
                break;
        }
    }
    return out->n;
}
