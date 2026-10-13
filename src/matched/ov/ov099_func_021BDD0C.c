/*
 * function: func_021BDD0C
 * address:  0x021BDD0C
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   GFL_NET_CopyInitParam  0x0203D844  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   d_021C3B9C     0x021C3B9C  data
 */
typedef struct {
    char pad[0x48];
    int f48;                /* 0x48 */
} Snd;

extern Snd d_021C3B9C;
extern int OS_IsRunOnTwl(void);
typedef unsigned int   u32;
struct Req;
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void GFL_NET_CopyInitParam(void *dst);

void func_021BDD0C(void *p, int on)
{
    if (OS_IsRunOnTwl())
        d_021C3B9C.f48 = 0x79000;
    else
        d_021C3B9C.f48 = 0x5e400;
    if (on)
        GFL_NET_StartSession((struct Req *)(&d_021C3B9C), 0, (u32)p);
    else
        GFL_NET_CopyInitParam(&d_021C3B9C);
}
