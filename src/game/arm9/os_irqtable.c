/*
 * file:     os_irqtable.c
 * unit:     yes
 * function: OSi_IrqCallback, OSi_IrqDma0, OSi_IrqDma1, OSi_IrqDma2, OSi_IrqDma3, OSi_IrqTimer0, OSi_IrqTimer1, OSi_IrqTimer2, OSi_IrqTimer3, OSi_IrqNDma0, OSi_IrqNDma1, OSi_IrqNDma2, OSi_IrqNDma3
 * address:  0x02084614
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableIrqMask         0x02084998  arm
 *   OSi_IrqCallbackInfo       0x02150F38  data
 *   OSi_IrqCallbackInfoIndex  0x020A868C  data
 *   SDK_AUTOLOAD_DTCM_START   0x02FE0000  data
 *   OSi_IrqCallback  0x02084614  arm
 */
typedef unsigned long u32;

typedef unsigned short u16;

typedef int BOOL;

typedef u32 OSIntrMode;

typedef struct OSIrqCallbackInfo {
    void (*func)(void *);
    u32 enable;
    void *arg;
} OSIrqCallbackInfo;

extern u32 OS_DisableIrqMask(u32 intr);
void OSi_IrqCallback(int dmaNo);
void OSi_IrqDma0(void);
void OSi_IrqDma1(void);
void OSi_IrqDma2(void);
void OSi_IrqDma3(void);
void OSi_IrqTimer0(void);
void OSi_IrqTimer1(void);
void OSi_IrqTimer2(void);
void OSi_IrqTimer3(void);
void OSi_IrqNDma0(void);
void OSi_IrqNDma1(void);
void OSi_IrqNDma2(void);
void OSi_IrqNDma3(void);
extern char SDK_AUTOLOAD_DTCM_START[];
extern OSIrqCallbackInfo OSi_IrqCallbackInfo[];
extern u16 OSi_IrqCallbackInfoIndex[];













/* HW_INTR_CHECK_BUF: the IRQ check word at DTCM + 0x3FF8. */
#define OSi_IRQ_CHECK_FLAG (*(volatile u32 *)((u32)SDK_AUTOLOAD_DTCM_START + 0x3FF8))













/*
 * sdk:      OSi_IrqCallback (os_irqtable.o)
 */
void OSi_IrqCallback(int index)
{
    u32 imask = 1UL << OSi_IrqCallbackInfoIndex[index];
    void (*callback)(void *) = OSi_IrqCallbackInfo[index].func;

    OSi_IrqCallbackInfo[index].func = 0;
    if (callback) {
        callback(OSi_IrqCallbackInfo[index].arg);
    }

    OSi_IRQ_CHECK_FLAG |= imask;

    if (!OSi_IrqCallbackInfo[index].enable) {
        (void)OS_DisableIrqMask(imask);
    }
}













/*
 * note:     os_irqTable.o OSi_IrqDma0; libmatch named the address CameraStandbyCallback.
 */
void OSi_IrqDma0(void)
{
    OSi_IrqCallback(0);
}












/*
 * note:     os_irqTable.o OSi_IrqDma1; libmatch named the address DWC_EnableHotspot.
 */
void OSi_IrqDma1(void)
{
    OSi_IrqCallback(1);
}











/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqDma2.
 */
void OSi_IrqDma2(void)
{
    OSi_IrqCallback(2);
}










/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqDma3.
 */
void OSi_IrqDma3(void)
{
    OSi_IrqCallback(3);
}









/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer0.
 */
void OSi_IrqTimer0(void)
{
    OSi_IrqCallback(8);
}








/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer1.
 */
void OSi_IrqTimer1(void)
{
    OSi_IrqCallback(9);
}







/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer2.
 */
void OSi_IrqTimer2(void)
{
    OSi_IrqCallback(10);
}






/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqTimer3.
 */
void OSi_IrqTimer3(void)
{
    OSi_IrqCallback(11);
}





/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma0.
 */
void OSi_IrqNDma0(void)
{
    OSi_IrqCallback(4);
}




/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma1.
 */
void OSi_IrqNDma1(void)
{
    OSi_IrqCallback(5);
}



/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma2.
 */
void OSi_IrqNDma2(void)
{
    OSi_IrqCallback(6);
}


/*
 * note:     os_irqTable.o wrapper; symbols_sdk names it OSi_IrqNDma3.
 */
void OSi_IrqNDma3(void)
{
    OSi_IrqCallback(7);
}
