/*
 * file:     unit_021CD3EC.c
 * unit:     yes
 * function: func_021CD3EC, func_021CD400, func_021CD404, func_021CD408
 * address:  0x021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void func_021CD3EC(void);
void func_021CD400(void);
void func_021CD404(void);
void func_021CD408(void);


/*
 * Call func_021CD400, func_021CD404, func_021CD408.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CD3EC.c \
 *       --func func_021CD3EC --addr 0x021CD3EC --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CD3EC(void)
{
    func_021CD400();
    func_021CD404();
    func_021CD408();
}

void func_021CD400(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CD404.c \
 *       --func func_021CD404 --addr 0x021CD404 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CD404(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CD408.c \
 *       --func func_021CD408 --addr 0x021CD408 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CD408(void)
{
}
