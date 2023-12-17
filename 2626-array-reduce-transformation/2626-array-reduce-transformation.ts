type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    let curr = init;
    if (nums.length === 0) return init;
    for (let i = 0;i < nums.length;i++) {
        curr = fn(curr, nums[i])
    }
    return curr;
};