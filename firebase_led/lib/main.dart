import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';

final referenceDatabase = FirebaseDatabase.instance;
final ref = referenceDatabase.reference();

void main() => runApp(MyApp());

void led_on(){
  ref.child("FirebaseLED").update({
    'LED_STATUS' : "on"
  });
}

void led_off(){
  ref.child("FirebaseLED").update({
    'LED_STATUS' : "off"
  });
}

class MyApp extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return MaterialApp(debugShowCheckedModeBanner: false,
      home: Scaffold(appBar:AppBar(title: Text("Firebase_LED"),),
        body: Center(child: Column(mainAxisAlignment: MainAxisAlignment.center ,
          children:[FlatButton(onPressed: (){
            led_on();
          }, child: Text("LED_ON"), color: Colors.red ),
            FlatButton(onPressed: (){
              led_off();
            },child: Text("LED_OFF"), color: Colors.black, textColor: Colors.white,)],
        )),
    ));
  }
}




