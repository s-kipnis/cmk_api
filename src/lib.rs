use std::str;

#[no_mangle]
pub fn entry(text: String) {
    println!("Hello, {}!", text);
}

#[no_mangle]
pub extern "C" fn command(text: *const u8, n: u32) {
    let zzz = unsafe { std::slice::from_raw_parts(text, n as usize) };
    let t = str::from_utf8(zzz);
    println!(
        "Hello, extern C {}!",
        t.unwrap_or_else(|_| "Invalid UTF-8 slice")
    );
}
