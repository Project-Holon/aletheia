/*
 * function: func_021C9184
 * address: 0x021C9184
 * packet: pkt_ov212_021C9184
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two zero alignment bytes at 021C91C2.
 * lever: assign the result in each arm after its stores, keeping r4 reusable.
 * symbols:
 *   func_021C8F7C 0x021C8F7C thumb ov212
 *   func_020307B0 0x020307B0 arm
 */
extern void func_021C8F7C(char *);
extern void func_020307B0(void *);
int func_021C9184(char *p)
{
    char *q=*(char **)(p+40);
    int result;
    switch(*(int *)(q+12)){
    case 0:
        func_021C8F7C(p);
        *(void **)(p+12)=*(void **)(q+16);
        *(unsigned short *)(p+16)=*(unsigned short *)(q+20);
        *(unsigned short *)(p+18)=1;
        result=3;
        break;
    case 1:
        *(unsigned short *)(p+18)=0;
        result=3;
        break;
    case 2:
    default:
        *(unsigned short *)(*(char **)p+14)=1;
        result=9;
        break;
    }
    func_020307B0(*(void **)(p+40));
    return result;
}
