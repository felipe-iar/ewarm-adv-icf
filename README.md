# Header-based module inclusion

:warning: EXPERIMENTAL

This is a simple demonstration on how to trick the ILINK so it becomes aware of which modules to include in the final app from the preprocessor perspective.

### `choices.h`
```
#ifdef USE_X
#pragma location=".usingX"
__root const int USING_X;
#warning Using X now...
extern int funX();
#endif
```
In this header, once `USE_X` is defined, a section `.usingX` is created.


### `app.icf`
The core aspect of this solution is summarised in this block:
```
define block ro_blkX { ro section .usingX,
                       ro object funx.o };                    
...
define block ro_others { ro } except { ro object fun*.o };

place in IROM_region { block ro_others,
                       block ro_blkX,
                       ...
```
- `ro_blkX` will contain the `.usingX` section followed by the object `funx.o`.
- If there is no `.usingX` section, the entire `ro_blkX` will not link.
