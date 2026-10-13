/*
 * function: BTL_CLIENT_TryLockCounter
 * address: 0x021D3FAC
 * packet: pkt_ov093_021D3FAC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Twenty-two code bytes plus two zero padding bytes at 021D3FC2;
 * the approved separate 021D3FC4 leaf and existing 021D3FD0 follow.
 */
typedef unsigned char u8;
typedef struct { u8 pad[2]; u8 f0:1,f1:1,f2:1,f3:1,f4:1,rest:3; } Flags;
int BTL_CLIENT_TryLockCounter(Flags *p)
{
    if (p->f1) return 0;
    p->f4 = 1;
    return 1;
}
