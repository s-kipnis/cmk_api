mod lib;
use crate::lib::{command, entry};

fn main() {
    entry("World".to_string());
    let v = "World".to_string();
    command(v.as_ptr(), v.len() as u32);
    let invalid_sequence = [0xF4, 0xBF, 0xBF, 0xBF];
    command(invalid_sequence.as_ptr(), 4);
}
