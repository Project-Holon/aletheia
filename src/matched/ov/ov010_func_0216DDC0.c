/*
 * function: FLDMMDL_SysSearchGridPos
 * address: 0x0216DDC0
 * packet: pkt_ov010_0216DDC0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_SysSearchGridPosList 0x0216DD60 thumb ov010
 */

typedef unsigned int u32;
typedef struct { int n; void *e[16]; } List;
extern int FLDMMDL_SysSearchGridPosList(u32 a, u32 b, u32 c, u32 d, List *out);
void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d)
{
    List out;
    if (FLDMMDL_SysSearchGridPosList(a, b, c, d, &out) != 0)
        return out.e[0];
    return 0;
}
