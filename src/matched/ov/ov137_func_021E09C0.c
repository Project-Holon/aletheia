/*
 * function: func_021E09C0
 * address: 0x021E09C0
 * packet: pkt_ov137_021E09C0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding at 0x021E0A42.
 * blocker: ARM9 0x0203F63C and 0x0203F5FC have no outside label/matched witness.
 * Verified ARM scratch C: S12/blocker_0203F63C-r1.log EXACT (72 bytes),
 * S13/blocker_0203F5FC-r1.log EXACT (64 bytes). Both use this symbol:
 *   FX_SinCosTable_ 0x020A1B38 data a2
 * typedef unsigned short u16;
 * extern const short FX_SinCosTable_[];
 * int func_0203F63C(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2 + 1];
 * }
 * int func_0203F5FC(u16 angle) {
 *     if (angle >= 360) return 0;
 *     return FX_SinCosTable_[((angle * 65535 / 360) >> 4) * 2];
 * }
 * symbols:
 *   func_021E15DC 0x021E15DC thumb ov137
 *   func_0203F63C 0x0203F63C arm
 *   func_0203F5FC 0x0203F5FC arm
 */
typedef unsigned short u16;
extern void func_021E15DC(int *,int);
typedef signed short   s16;
typedef unsigned int   u32;
extern s16 func_0203F63C(u32 x);
extern int func_0203F5FC(u32 x);
void func_021E09C0(char *p,int *q,int amount,int extra)
{
    u16 angle;
    func_021E15DC(&amount,*(int *)(p+0x20));
    angle=amount/4096;
    *(int *)(p+0x44)=*(int *)(p+0x50)+q[0]+22*func_0203F63C(angle);
    *(int *)(p+0x48)=extra+(*(int *)(p+0x54)-0x6000+q[1]);
    *(int *)(p+0x4c)=*(int *)(p+0x58)+q[2]+22*func_0203F5FC(angle);
    *(short *)(p+0x24)=*(int *)(p+0x2c)/4096;
    *(short *)(p+0x26)=*(int *)(p+0x30)/4096;
    *(short *)(p+0x28)=*(int *)(p+0x34)/4096;
}
