// if you checked "fancy-settings" in extensionizr.com, uncomment this lines

// var settings = new Store("settings", {
//     "sample_setting": "This is how you use Store.js to remember values"
// });


//example of using a message handler from the inject scripts
chrome.extension.onMessage.addListener(
  function(request, sender, sendResponse) {
 
  });

function show(content, title) {
  var img_path = 'src/bg/logo.png';
  // var notification = window.webkitNotifications.createNotification(
  //   img_path,                      // The image.
  //   title, // The title.
  //   content      // The body.
  // );
  var notification = new Notification(title, { icon: img_path, body: content });
  notification.addEventListener('click', function() {
	    notification.cancel();
	});
  notification.show();
}

// Conditionally initialize the options.
if (!localStorage.isInitialized) {
  localStorage.isActivated = true;   // The display activation.
  localStorage.frequency = 1;        // The display frequency, in minutes.
  localStorage.isInitialized = true; // The option initialization.
}

// Test for notification support.
if (window.webkitNotifications) {
  // show('cool');
}

Firebase.enableLogging(true);
var f = new Firebase('https://notificationcis22c.firebaseio.com/');

f.on('child_added', function(s) {
  // $.getJSON("https://sync-awfhiu1251251hi.firebaseio.com/.json?print=pretty&format=export&download=sync-awfhiu1251251hi-export.json&auth=eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJhZG1pbiI6dHJ1ZSwidiI6MCwiZCI6eyJmb3JnZSI6dHJ1ZX0sImlhdCI6MTM5NDMzMzIyM30.h3pnnpiC-3i4Zp3A6wyYckhJ49deCwIvQ4v_qIewvQs")
  show(s.val().content, s.val().title);
  // show();
});


// var bkg = chrome.extension.getBackgroundPage();
// bkg.console.log('foo');