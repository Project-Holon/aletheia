/*
 * function: func_021BBA4C
 * address: 0x021BBA4C
 * packet: pkt_ov099_021BBA4C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: binding the window address before the gender-zero call preserves its separate hoist and call site; form/gender declaration order fixes their spills.
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020456F8 0x020456F8 arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void *func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_0201F73C(void *,int,u16,int);
extern void *func_020457B0(u32,u32);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void func_020456F8(void *);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *,u32);
extern u32 func_02017E1C(void *,u32,u32);
extern void func_02045CAC(void *,u32,void *);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32);
extern void func_0201F250(void *,void *,void *);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(void *);
extern void func_02045374(void *);
extern void func_02045334(void *);
extern void func_02041B6C(u32);
void func_021BBA4C(char *p,void *party)
{
    void *s,*t,*mon;
    int n,i,off;
    u32 species,gender,name,form;
    void **w;
    void *win;
    if (*(void **)(p+0x1a0)==0)
        *(void **)(p+0x1a0)=func_020450F0(2,1,5,30,6,15,1);
    func_0201F73C(*(void **)(p+0x1a0),2,*(u32 *)(p+0x1334),14);
    s=func_020457B0(0x40,0x21);
    t=func_020457B0(0x40,0x21);
    func_02043B5C(func_02045770(*(void **)(p+0x1a0)),255);
    func_020456F8(*(void **)(p+0x1a0));
    n=func_0201AA18(party);
    for (i=0;i<n;i++) {
        mon=func_0201AB28(party,i);
        if (func_02017E1C(mon,0x4c,0)==0) {
            species=func_02017E1C(mon,0,0);
            form=func_02017E1C(mon,0xad,0);
            name=func_02017E1C(mon,0x9e,0);
            gender=func_02017E1C(mon,0x6e,0);
            func_02045CAC(*(void **)(p+0xe0),0x74,t);
            func_0201EFA4(*(void **)(p+0xdc),0,name,3,0,1);
            func_0201F250(*(void **)(p+0xdc),s,t);
            off=i*40;
            func_0201C7A4(func_02045770(*(void **)(p+0x1a0)),off+1,32,s,*(void **)(p+0xec));
            if (gender!=2 && ((species!=0x1d && species!=0x20) || form!=0)) {
                if (gender==0) {
                    w=(void **)(p+0x1a0);
                    func_02045CAC(*(void **)(p+0xe0),0x75,t);
                    win=*w;
                } else {
                    func_02045CAC(*(void **)(p+0xe0),0x76,t);
                    win=*(void **)(p+0x1a0);
                }
                func_0201C7A4(func_02045770(win),off+30,16,t,*(void **)(p+0xe8));
            }
        }
    }
    func_02045808(s);
    func_02045808(t);
    func_02045374(*(void **)(p+0x1a0));
    func_02045334(*(void **)(p+0x1a0));
    func_02041B6C(2);
}
