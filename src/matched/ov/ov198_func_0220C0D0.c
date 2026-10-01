/*
 * function: func_0220C0D0
 * address: 0x0220C0D0
 * packet: pkt_ov198_0220C0D0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 value and a seven-bit unsigned field preserve spill and load widths.
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201EF8C 0x0201EF8C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Bits { unsigned char low:7; unsigned char high:1; } Bits;
extern int func_022110D4(u8 *,int);
extern void *func_02045EC0(void *,u32);
extern u32 func_02045770(void *);
extern void func_0201C724(u32,u32,u16,u32,u32,u32,u16);
extern void func_02045808(void *);
extern u32 func_020457B0(u32,u32);
extern void func_0201EFA4(void *,u32,u32,u32,u32,u32);
extern void func_0201F250(void *,u32,void *);
extern void func_0201EF8C(void *,u32,u32);
void func_0220C0D0(u8 *p,int slot,int index,u16 value,u8 extra)
{
    char *elem=(char *)(p+4)+func_022110D4(p,index)*0x4C;
    void *text=func_02045EC0(*(void **)(p+0x1EA0),11);
    u32 context;
    u32 surface;
    func_0201EFA4(*(void **)(p+0x1EA4),0,((Bits *)(elem+0x16))->low,3,0,1);
    func_0201F250(*(void **)(p+0x1EA4),*(u32 *)(p+0x1EA8),text);
    context=*(u32 *)(p+0x1EAC);
    surface=func_02045770(*(void **)(p+slot*8+0x1F70));
    func_0201C724(context,surface,value,extra,*(u32 *)(p+0x1EA8),*(u32 *)(p+0x1E9C),0x3DC0);
    (p+slot*8)[0x1F74]=1;
    func_02045808(text);
}
