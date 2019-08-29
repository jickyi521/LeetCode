//
//  AppDelegate.swift
//  LeetCode
//
//  Created by Eason Qian on 2019/8/27.
//  Copyright © 2019 Eason Qian. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        print(twoSum([-1,-2,-3,-4,-5], -8))
        
//        print(addSum(1, 2))
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }
    
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
         for i in 0..<nums.count {
           let item = nums[i]
           let remainItem = target - item
                for j in (i+1)..<nums.count {
                    if (nums[j] == remainItem) {
                        return [i, j]
                    }
                }
       }
       return []
    }
    
    func addSum(_ a: Int, _ b: Int) -> Int {
           print(a)
           return a+b
    }


}

