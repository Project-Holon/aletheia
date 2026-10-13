/*
 * function: ov208_func_021C50F8
 * address:  0x021C50F8
 * packet:   pkt_ov208_021C50F8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MCSS_GetPosition  0x02015C30  thumb
 *   data_021C8E40  0x021C8E40  data
 */

typedef unsigned int u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

struct Ov208Cam {
    u32 pad0[6];
    Vec ofs;
};

extern void MCSS_GetPosition(void *p, u32 *out);
extern struct Ov208Cam data_021C8E40;

void ov208_func_021C50F8(u32 obj, Vec *out)
{
    Vec v;

    MCSS_GetPosition((void *)obj, (u32 *)(&v));
    out->x = v.x + data_021C8E40.ofs.x;
    out->y = v.y + data_021C8E40.ofs.y;
    out->z = v.z + data_021C8E40.ofs.z;
}
