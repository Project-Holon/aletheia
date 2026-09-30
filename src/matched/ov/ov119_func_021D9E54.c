/*
 * function: func_021D9E54
 * address: 0x021D9E54
 * packet: pkt_ov119_021D9E54
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021D8C6C 0x021D8C6C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9E0C 0x021D9E0C thumb ov119
 */

extern void func_021B6558(int,int,int);
extern void func_0204B3DC(int,int);
extern void func_021D8C6C(void *);
extern void func_021D8E84(void *,int);
extern void func_021D9E0C(void *);
void func_021D9E54(char *p) {
    func_021B6558(*(int *)(p+0x9C0),7,0);
    func_021B6558(*(int *)(p+0x9C0),8,0);
    func_021B6558(*(int *)(p+0x9C0),9,0);
    func_021B6558(*(int *)(p+0x9C0),1,0);
    func_0204B3DC(*(int *)(p+0xF04),0);
    func_021D8C6C(p);
    func_021D8E84(p,(int)func_021D9E0C);
}
