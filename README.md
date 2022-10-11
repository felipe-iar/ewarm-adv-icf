# Header-based module inclusion

:warning: EXPERIMENTAL

This is a simple demonstration on how to trick the ILINK so it becomes aware of which modules to include in the final app from the preprocessor perspective.

### `choices.h`
https://github.com/felipe-iar/ewarm-adv-icf/blob/2f5ed6fce0c443f7a99dc1a5bbc074d2ef4791c5/choices.h#L8-L13

In this header, once `USE_X` is defined, a section `.usingX` is created.


### `app.icf`
The core aspect of this solution is summarised in this block:
https://github.com/felipe-iar/ewarm-adv-icf/blob/2f5ed6fce0c443f7a99dc1a5bbc074d2ef4791c5/app.icf#L149-L164

- `ro_blkX` will contain the `.usingX` section followed by the object `funx.o`.
- If there is no `.usingX` section, the entire `ro_blkX` will not link.
