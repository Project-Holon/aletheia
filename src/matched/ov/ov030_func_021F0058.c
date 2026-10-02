/*
 * function: func_021F0058
 * address: 0x021F0058
 * packet: pkt_ov030_021F0058
 * region: ov030
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: empty ov030 callback func_021F00C4 now matched in its own shard.
 * interface: caller sets r2=0x149 despite two-input thunk/leaf; retained
 * in the caller extern to reproduce original argument setup.
 * symbols:
 *   func_021EFF54 0x021EFF54 thumb ov030
 *   func_021EFECC 0x021EFECC thumb ov030
 *   func_021EFEC4 0x021EFEC4 thumb ov030
 *   func_021F00C4 0x021F00C4 thumb ov030
 */
extern void func_021EFF54(void);
extern void func_021EFECC(void *);
extern void func_021EFEC4(void *, void (*)(void *), int);
extern void func_021F00C4(void *);
void func_021F0058(void *p)
{
    func_021EFF54();
    func_021EFECC(p);
    func_021EFEC4(p, func_021F00C4, 0x149);
}
