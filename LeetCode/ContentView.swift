//
//  ContentView.swift
//  LeetCode
//
//  Created by Eason Qian on 2019/8/27.
//  Copyright © 2019 Eason Qian. All rights reserved.
//

import SwiftUI


struct ContentView: View {
    
    
//    let nums = addSum(1, 2) //twoSum(_num: [1, 8], target: 9)
    
    var body: some View {
        Text("Hello World")
//        Text("\(nums)")
    }
    
    
    static func addSum(_ a: Int, _ b: Int) -> Int {
        print(a)
        return a+b
    }
    
    static func twoSum(_ num: [Int], _ target: Int) -> [Int] {
        for i in 0..<num.count {
            let item = num[i]
            print("\(item)")
        }
        
        return num
    }
}

#if DEBUG
struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
#endif
