/*
 * function: func_021D97CC
 * address: 0x021D97CC
 * packet: pkt_ov123_021D97CC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: copy the 64-byte halfword table as an aggregate; checksum occupies the high word,
 * with its call result held until after arg initialization. Bind the narrowed digit index
 * before shifting v, then load the indexed halfword in the call argument.
 * symbols:
 *   func_0203F1FC 0x0203F1FC arm
 *   func_0204581C 0x0204581C arm
 *   func_02045AFC 0x02045AFC arm
 *   d_021DA868 0x021DA868 data a2
 *   d_021DA864 0x021DA864 data a2
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { u16 a[32]; } Table;
extern const Table d_021DA868;
extern const u16 d_021DA864;
extern int func_0203F1FC(const u8 *src, u32 len);
struct U16Vec;
extern void func_0204581C(struct U16Vec *vec);
extern void func_02045AFC(struct U16Vec *vec, u16 value);
extern void func_0201D60C(void *s, u32 b, u32 c, u16 n, const u16 *arr);
void func_021D97CC(int value, void *p)
{
    Table table;
    int copy;
    u32 checksum;
    u16 arg;
    u64 v;
    int i;
    table=d_021DA868;
    copy=value;
    checksum=func_0203F1FC((const u8 *)(&copy),4);
    arg=d_021DA864;
    v=(u64)(long long)copy+((u64)checksum<<32);
    func_0204581C(p);
    for (i=0;i<10;i++) {
        u16 index;
        index=(u16)(v&31);
        v>>=5;
        func_02045AFC(p,table.a[index]);
        func_0201D60C(p,189,4,1,&arg);
    }
}
