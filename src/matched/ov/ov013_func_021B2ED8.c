/*
 * function: VCT_POOL_InitFrames
 * address: 0x021B2ED8
 * packet: pkt_ov013_021B2ED8
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * lever: fill call takes data, p and b; r1/r2 stay live across the guards.
 * symbols:
 *   gVoiceFramePool 0x021B4C24 data a4
 *   func_02082AC0 0x02082AC0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct E { struct E *next; u8 pad[0x474]; } E;
typedef struct { E *cur; E *buf; } G;
extern G gVoiceFramePool;
extern void func_02082AC0(int, void *, u32);
int VCT_POOL_InitFrames(E *a, u32 b)
{
    u32 i;
    u32 n;
    E *p;
    n = b / 0x478;
    p = a;
    gVoiceFramePool.buf = p;
    if (n < 4 || n > 0x48) return 0;
    if (p == 0) return 0;
    if ((u32)p & 0x1f) {
        gVoiceFramePool.buf = 0;
        return 0;
    }
    i = 0;
    func_02082AC0(i, p, b);
    for (i = 0; i < n - 1; i++)
        gVoiceFramePool.buf[i].next = &gVoiceFramePool.buf[i + 1];
    (gVoiceFramePool.buf + n)[-1].next = 0;
    gVoiceFramePool.cur = gVoiceFramePool.buf;
    return 1;
}
