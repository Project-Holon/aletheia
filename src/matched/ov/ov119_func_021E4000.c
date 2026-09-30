/*
 * function: func_021E4000
 * address: 0x021E4000
 * packet: pkt_ov119_021E4000
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E43DC 0x021E43DC thumb ov119
 *   func_0203FB44 0x0203FB44 arm
 */
extern void func_021E43DC(char *);
extern void func_0203FB44(int, unsigned short, unsigned short);
void func_021E4000(char *p)
{
    func_021E43DC(p);
    if (*(unsigned int *)(p + 0x870)) {
        func_0203FB44(5, *(unsigned int *)(p + 0x870), (unsigned short)(*(unsigned int *)(p + 0x870) >> 16));
        *(int *)(p + 0x870) = 0;
    }
    if (*(unsigned int *)(p + 0x874)) {
        func_0203FB44(7, *(unsigned int *)(p + 0x874), (unsigned short)(*(unsigned int *)(p + 0x874) >> 16));
        *(int *)(p + 0x874) = 0;
    }
    if (*(unsigned int *)(p + 0x644)) {
        func_0203FB44(6, *(unsigned int *)(p + 0x644), (unsigned short)(*(unsigned int *)(p + 0x644) >> 16));
        *(int *)(p + 0x644) = 0;
    }
}
