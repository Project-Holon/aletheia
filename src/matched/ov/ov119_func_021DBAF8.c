/*
 * function: func_021DBAF8
 * address: 0x021DBAF8
 * packet: pkt_ov119_021DBAF8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E4420 0x021E4420 thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DBE70 0x021DBE70 thumb ov119
 */
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern void func_021D8980(char *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_021E4420(char *p);
extern void func_021E6700(void *);
extern void func_021D8B38(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DBE70(char *p);
void func_021DBAF8(char *p)
{
    func_021B6558((unsigned char *)(*(int *)(p+0x9c0)),8,0);
    func_021B6558((unsigned char *)(*(int *)(p+0x9c0)),7,1);
    func_021B6548((unsigned char *)(*(int *)(p+0x9c0)),7,1);
    func_021B6558((unsigned char *)(*(int *)(p+0x9c0)),9,0);
    func_021D8980(p);
    func_0204B3DC((struct Obj *)*(int *)(p+0xf04),1);
    func_021E4420(p);
    func_021E6700(p);
    *(int *)(p+0xf84)=-1;
    *(int *)(p+0xf88)=-1;
    func_021D8B38(p);
    func_021D8E84(p,(int)func_021DBE70);
}
