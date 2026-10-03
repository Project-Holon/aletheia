/*
 * function: func_021FF58C
 * address: 0x021FF58C
 * packet: pkt_ov135_021FF58C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F50EC 0x021F50EC thumb ov135
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020120F4 0x020120F4 thumb
 *   func_021F6B34 0x021F6B34 thumb ov135
 *   func_021F6B80 0x021F6B80 thumb ov135
 *   func_021F6B40 0x021F6B40 thumb ov135
 *   func_02031348 0x02031348 arm
 *   str_02203E30 0x02203E30 data a1
 *   d_021DC800 0x021DC800 data ov131 a4
 *   ov131_id 0x83 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    void *mon, *ctx, *save;
    u8 type, fD, fE, fF, f10, pad11[3];
    u16 f14, pad16;
    void *f18;
    u32 f1C, f20, f24;
} Request;
extern const char str_02203E30[], ov131_id[];
extern const u32 d_021DC800[];
extern void func_021F50EC(u8 *);
extern void *func_02030734(u32,u32,u32,const char *,u32);
extern void func_02082BCC(void *,u32,u32);
extern void *func_020120F4(void *);
extern int func_021F6B34(int);
extern int func_021F6B80(void *,void *,int);
extern void *func_021F6B40(void *,void *,int,int);
extern void func_02031348(void *,u32,const void *,void *);
void func_021FF58C(u8 *p)
{
    Request *r;
    func_021F50EC(p);
    *(Request **)(p+0x10DC)=func_02030734(0x48,sizeof(Request),0,str_02203E30,0x4C);
    func_02082BCC(*(Request **)(p+0x10DC),0,sizeof(Request));
    r=*(Request **)(p+0x10DC);
    r->ctx=*(void **)(*(u8 **)p+0x20);
    r->save=func_020120F4(*(void **)(*(u8 **)p+0x40));
    if(func_021F6B34(*(u16 *)(p+0xC4)))
        r->fE=func_021F6B80(*(void **)(*(u8 **)p+8),*(void **)(*(u8 **)p+12),*(u16 *)(p+0xC4));
    else r->fE=30;
    r->fF=*(u16 *)(p+0xC6);
    r->fD=1;
    r->f14=0;
    r->f10=0;
    r->f18=*(void **)(*(u8 **)p+0x2C);
    r->f20=0;
    if(func_021F6B34(*(u16 *)(p+0xC4))) {
        r->mon=*(void **)(*(u8 **)p+8);
        r->type=1;
    } else {
        r->mon=func_021F6B40(*(void **)(*(u8 **)p+8),*(void **)(*(u8 **)p+12),*(u16 *)(p+0xC4),0);
        r->type=2;
    }
    func_02031348(*(void **)(p+0x12F0),(u32)ov131_id,d_021DC800,r);
    *(u32 *)(p+0xB8)=1;
}
