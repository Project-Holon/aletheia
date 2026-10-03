/*
 * function: func_021BA160
 * address: 0x021BA160
 * packet: pkt_ov225_021BA160
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: args before table declaration puts the 64-byte copy at sp+0.
 * symbols:
 *   d_021BBF4C 0x021BBF4C data a4
 *   func_02082BCC 0x02082BCC arm
 *   func_021B9A08 0x021B9A08 thumb ov225
 *   func_021B62E0 0x021B62E0 thumb ov067
 *   func_021B6558 0x021B6558 thumb ov067
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct {u8 *f0;u32 f4;int f8;u32 fC,f10,f14;int f18,f1c;} A;
typedef struct {int f0;u32 f4;int f8;u8 sub[0x14];u8 elem[1];} R;
struct Block {u32 words[16];};
extern const struct Block d_021BBF4C;
extern void func_02082BCC(void *,u8,u32);
extern u32 func_021B9A08(const u8 *p);
extern R *func_021B62E0(A *,int);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
void func_021BA160(char *p)
{
    A args;
    struct Block table=d_021BBF4C;
    func_02082BCC(&args,0,sizeof(args));
    args.f0=(u8 *)&table;args.f4=2;
    args.f8=(int)func_021B9A08(*(void **)(*(char **)p+8));
    args.fC=6;args.f10=3;args.f14=1;args.f18=0;
    *(R **)(p+4)=func_021B62E0(&args,*(unsigned short *)(*(char **)p+4));
    func_021B6558(*(void **)(p+4),0,0);
}
