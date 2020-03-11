const area  = document.getElementById('pub_msg_input')
const btn   = document.getElementById('msg_send_bt')
let interval
let i = 0 
$('#huya-ab').on('DOMNodeInserted',function(){
    interval = setInterval(function () {
        area.value = "一条弹幕"     //弹幕内容
        let time=document.getElementsByClassName("msg_send_time")
        if (time[0]==undefined || time[0].innerHTML==0) {
          btn.setAttribute("class", "btn-sendMsg hiido_stat enable")
          btn.click()
          i++
          if( i>=5 ) {   //重复次数
            clearInterval(interval)
          }
        }   
      }, 1000)      //弹幕间隔，1000毫秒=1秒
})
