/*
 * function: func_021BA980
 * address: 0x021BA980
 * packet: pkt_ov218_021BA980
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: heap extern parameters widened where original forwards r5 without truncation; BG and flag callee parameters narrowed to u8 where A9AC-A9CE shows explicit shifts. 414AC visibly receives BG input despite its legacy asm void prototype.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   d_021BAEAC 0x021BAEAC data a4
 *   d_021BAF28 0x021BAF28 data a4
 */
typedef struct Record { unsigned bg; unsigned config[8]; unsigned type, enable; } Record;
extern const unsigned d_021BAEAC[];
extern const Record d_021BAF28[];
extern void func_02082BCC(void *, int, int);
extern void func_0203F8F4(unsigned);
extern void func_02045088(unsigned);
extern void func_0203FC28(const unsigned *);
extern void func_0203FCA0(unsigned char, const void *, unsigned char);
extern void func_020414AC(unsigned char);
extern void func_02040588(unsigned char, unsigned char);
void func_021BA980(char *ctx, unsigned heap)
{
    unsigned i;
    const Record *record;
    unsigned bg;
    func_02082BCC(ctx, 0, 4);
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28(d_021BAEAC);
    for (i = 0; i < 7; i++) {
        record = &d_021BAF28[i];
        bg = record->bg;
        func_0203FCA0(bg, record->config, record->type);
        func_020414AC(bg);
        func_02040588(bg, record->enable);
    }
}
