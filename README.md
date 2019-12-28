# xbrpc
An effort at a small front-end for xbrpc.

This is a work-in-progress that I work on sparingly.

![screenshot](meta/screen.png)

**TODO**:
- Add more data types as arguments (`char`, `bool`, ) even though these can all be done simply using.
- Clean up the source of `xbrpc` and merge it into this repository. 
- Add return type information (requires defining a more serious protocol).
- Potentially add length-prefixing to the protocol since right now I'm relying on fairly consistent TCP windowing sizes.
