/*
 * function: func_021C0A54
 * address: 0x021C0A54
 * packet: pkt_ov110_021C0A54
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   func_021B6588 0x021B6588 thumb ov067
 *   data_021C39F8 0x021C39F8 data a4
 */
typedef struct { unsigned v[8]; } Table;
typedef struct { Table *table; unsigned count; void *p; unsigned mode,a,b,c,d; } Descriptor;
extern const Table data_021C39F8;
extern void *TOUCHBAR_Create(Descriptor *,int);
extern void func_021B6588(unsigned char *p, unsigned int id, unsigned int v);
void *func_021C0A54(int unused,void *p,int heap) {
    Descriptor desc={0};
    Table table=data_021C39F8;
    void *out;
    desc.count=1;
    desc.mode=1;
    desc.a=14;
    desc.b=5;
    desc.c=1;
    desc.table=&table;
    desc.p=p;
    out=TOUCHBAR_Create(&desc,heap);
    func_021B6588(out,1,1);
    return out;
}
