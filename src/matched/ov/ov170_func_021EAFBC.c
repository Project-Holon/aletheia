/*
 * function: func_021EAFBC
 * address: 0x021EAFBC
 * packet: pkt_ov170_021EAFBC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021EAAE4 0x021EAAE4 thumb ov170
 *   func_021EAC28 0x021EAC28 thumb ov170
 *   func_0201D304 0x0201D304 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_021EABA0 0x021EABA0 thumb ov170
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { unsigned char pad[18]; unsigned char low:7,high:1; } Entry;
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u32);
extern void func_021EAAE4(char *,u32);
extern void func_021EAC28(char *,int,void *,u32,int,int,u32,u16);
extern u32 func_0201D304(void *,u32,u32);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32);
extern void func_021EABA0(void **);
#define W(p) (*(char **)((p)+44))
void func_021EAFBC(char *p,const Entry *e,u32 i)
{
    u16 n;
    u32 text;
    func_02043B5C(func_02045770(*(void **)(W(p)+i*8+148)),0);
    if (e->high == 0) {
        if (*(u32 *)(W(p)+380) == 1)
            n = *(u16 *)((const char *)e+4);
        else
            n = *(u16 *)(*(char **)(W(p)+384)+*(u16 *)((const char *)e+4)*2);
        if (n != 999) {
            func_021EAC28(W(p),i,*(void **)(W(p)+128),108,0,0,*(u32 *)(W(p)+120),1088);
            text=func_0201D304(*(void **)(W(p)+136),*(u32 *)(W(p)+120),0);
            func_0201EFA4(*(void **)(W(p)+132),0,n,3,2,1);
            func_021EAC28(W(p),i,*(void **)(W(p)+128),104,text,0,*(u32 *)(W(p)+120),1088);
        } else { func_021EAAE4(W(p),i); return; }
    } else { func_021EAAE4(W(p),i); return; }
    func_021EABA0((void **)(W(p)+148+i*8));
}
