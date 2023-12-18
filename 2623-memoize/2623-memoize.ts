type Fn = (...params: number[]) => number

function memoize(fn: Fn): Fn {
    let cache = {}
    return function(...args) {
        let key = JSON.stringify(args);
        if (key in cache) {
            return cache[key];
        } else {
            let ans = fn(...args)
            cache[key] = ans;
            return ans;
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */