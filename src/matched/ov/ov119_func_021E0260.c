/*
 * function: func_021E0260
 * address: 0x021E0260
 * packet: pkt_ov119_021E0260
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_020307B0(void *);
extern void func_02082BCC(void *,int,int);
void func_021E0260(char *p)
{
    int zero;
    if (*(void **)(p+0x60c)) func_020307B0(*(void **)(p+0x60c));
    if (*(void **)(p+0x610)) func_020307B0(*(void **)(p+0x610));
    if (*(void **)(p+0x614)) func_020307B0(*(void **)(p+0x614));
    if (*(void **)(p+0x618)) func_020307B0(*(void **)(p+0x618));
    if (*(void **)(p+0x61c)) func_020307B0(*(void **)(p+0x61c));
    if (*(void **)(p+0x620)) func_020307B0(*(void **)(p+0x620));
    if (*(void **)(p+0x624)) func_020307B0(*(void **)(p+0x624));
    zero=0;
    func_02082BCC(p+0x60c,zero,36);
    p[0x11f7]=zero;
}
