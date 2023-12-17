type ToBeOrNotToBe = {
    toBe: (val: any) => boolean;
    notToBe: (val: any) => boolean;
};

function expect(val: any): ToBeOrNotToBe {
    const ans: ToBeOrNotToBe = {
        toBe: (_val: any) => {
            if (_val === val) return true;
            else {
                throw new Error("Not Equal")
            }
        },
        notToBe: (_val: any) => {
            if (_val !== val) return true;
            else {
                throw new Error("Equal")
            }
        } 
    }
    return ans;
    
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */