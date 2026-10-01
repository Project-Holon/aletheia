/*
 * function: func_021FC754
 * address: 0x021FC754
 * packet: pkt_ov186_021FC754
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021FC870 0x021FC870 thumb ov186
 *   func_0201C724 0x0201C724 thumb
 */
typedef struct Pair {int x,y;} Pair;
extern void *func_02045770(void *);
extern void func_02043B5C(void *,unsigned char);
extern void func_02045CAC(void *,void *,void *);
extern void func_021FC870(int,Pair *,const void *,void *,void *,Pair *);
extern void func_0201C724(void *,void *,short,short,void *,void *,unsigned short);
void func_021FC754(char *p,void *a,void *b,void *font,unsigned short value)
{
    Pair xy;
    void *owner;
    func_02043B5C(func_02045770(*(void **)(p+12)),*(unsigned short *)(p+20));
    func_02045CAC(a,b,*(void **)(p+16));
    func_021FC870(*(int *)(p+24),(Pair *)(p+28),func_02045770(*(void **)(p+12)),*(void **)(p+16),font,&xy);
    owner=*(void **)(p+8);
    func_0201C724(owner,func_02045770(*(void **)p),xy.x,xy.y,*(void **)(p+16),font,value);
    p[4]=1;
}
