/*
 * function: func_02184780
 * address: 0x02184780
 * packet: pkt_ov168_02184780
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x02184816.
 * blocker: ARM9 0x0203F5FC has no outside code witness.
 * Verified blocker C copied from ov137_func_021E09C0.c;
 * S13/blocker_0203F5FC-r1.log reports EXACT, 64 bytes:
 *   symbols: d_020A1B38 0x020A1B38 data a2
 *   typedef unsigned short u16;
 *   extern const short d_020A1B38[];
 *   int func_0203F5FC(u16 angle) {
 *       if (angle >= 360) return 0;
 *       return d_020A1B38[((angle * 65535 / 360) >> 4) * 2];
 *   }
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_0203F5FC 0x0203F5FC arm
 *   func_0204B550 0x0204B550 arm
 *   func_02030EAC 0x02030EAC arm
 */
typedef signed short s16;
typedef unsigned short u16;
extern void func_0204B3DC(void *, int);
extern void func_0207C9D0(void *, void *, void *);
typedef unsigned int   u32;
extern int func_0203F5FC(u32 x);
extern void func_0204B550(void *, s16, int);
struct Node;
extern void func_02030EAC(struct Node *n);
void func_02184780(void *task, int *p)
{
    s16 x;
    s16 y;
    int angle;
    if (p[1] != 0) {
        p[1]--;
        if (p[1] == 0)
            func_0204B3DC((void *)p[0], 1);
        return;
    }
    func_0207C9D0(p + 2, p + 5, p + 2);
    x = p[2] >> 12;
    y = p[3] >> 12;
    p[8] += p[9];
    while (p[8] > 0x168000)
        p[8] -= 0x168000;
    angle = func_0203F5FC((u16)(p[8] >> 12));
    x += (s16)((p[10] * angle) >> 12);
    func_0204B550((void *)p[0], x, 0);
    func_0204B550((void *)p[0], y, 1);
    if (y < -16) {
        func_0204B3DC((void *)p[0], 0);
        func_02030EAC(task);
        p[11] = 0;
    }
}
