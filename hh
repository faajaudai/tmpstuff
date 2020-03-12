const area  = document.getElementById('pub_msg_input')
const btn   = document.getElementById('msg_send_bt')

let idx = 0 
let interval1
let interval2
$('#huya-ab').on('DOMNodeInserted',function(){
    doSomething()
    let beginTime = new Date().getTime()
    let endTime
    interval1 = setInterval(function () {
        doSomething()
        endTime = new Date().getTime()
        if ( (endTime-beginTime) > 60000 ){     //运行总时长，单位毫秒
            clearInterval(interval1)
            console.log("exit")
        }
      }, 20000)      //每组弹幕间隔，1000毫秒=1秒
})


function doSomething(){
    doDanmu()
    interval2 = setInterval(function(){
        doDanmu()
    }, 2000)        //每条弹幕间隔，1000ms=1s
}

function doDanmu(){
    area.value = "666667"     //弹幕内容
    let time=document.getElementsByClassName("msg_send_time")
    if (time[0]==undefined || time[0].innerHTML==0) {
      btn.setAttribute("class", "btn-sendMsg hiido_stat enable")
      btn.click()
      idx++
      if( idx>=3 ) {            //重复次数
        clearInterval(interval2)
        idx=0
      }
    }   
}
