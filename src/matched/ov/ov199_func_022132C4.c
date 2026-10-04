/*
 * function: func_022132C4
 * address: 0x022132C4
 * packet: pkt_ov199_022132C4
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 Thumb tails 0200BA58 and 0200BA68 lack matched/label witnesses.
 * Scratch-only tails each EXACT 16B; blocker-0200BA58.log and blocker-0200BA68.log.
 * TU/suggest-split MATCH: no viable partition; Ilias owns ARM9 filing.
 * Verified blocker C (symbols: ov188_id 0x000000BC data a1;
 * func_02034AC4 0x02034AC4 arm; func_02034A5C 0x02034A5C arm):
 * extern const char ov188_id[];
 * extern void func_02034AC4(const void *);
 * extern void func_02034A5C(const void *);
 * void func_0200BA58(void) { func_02034AC4(ov188_id); }
 * void func_0200BA68(void) { func_02034A5C(ov188_id); }
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02034AC4 0x02034AC4 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021EEEA8 0x021EEEA8 thumb ov188
 *   func_0200BA58 0x0200BA58 thumb
 *   func_0200BA68 0x0200BA68 thumb
 *   ov093_id 0x0000005D data a1
 *   d_02213D04 0x02213D04 data ov199 a1
 */
extern void *func_02030734(int, unsigned int, int, const char *, int);
extern void func_02082BCC(void *, int, unsigned int);
extern void func_02034AC4(const void *);
extern void func_02034A5C(const void *);
extern void func_020130C4(char *);
extern void func_020138C4(char *, void *, int);
extern void func_0200BA58(void);
extern void func_0200BA68(void);
extern void func_021EEEA8(char *, int);
extern void func_02005D28(void);
extern void func_02005D90(unsigned short, int);
extern const char d_02213D04[];
extern const char ov093_id[];
void *func_022132C4(void *unused, int heap, char *p)
{
    char *work = func_02030734(heap, 0xf0, 0, d_02213D04, 0x6f4);
    func_02082BCC(work, 0, 0xf0);
    func_02034AC4(ov093_id);
    func_020130C4(work);
    func_020138C4(work, *(void **)(p + 4), heap);
    func_02034A5C(ov093_id);
    func_0200BA58();
    func_021EEEA8(work, heap);
    func_0200BA68();
    func_02034AC4(ov093_id);
    func_02005D28();
    func_02005D90(*(unsigned short *)(work + 0x18), 0xffff);
    return work;
}
