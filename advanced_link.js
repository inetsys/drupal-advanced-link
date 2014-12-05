var advancedLinkFileHandler = function(){
	console.log('default');
};

var advancedLinkImceBrowser = null;

var advancedLinkImceLoad = function(win){
	//win.imce.opDisable('delete');
	win.imce.setSendTo('Insert file as a link', advancedLinkFileHandler);
}

function openImce(field){
	advancedLinkFileHandler = function(file, win){
		jQuery('#' + field).val(file.url);
		win.close();
		advancedLinkImceBrowser = null;
	};

	if(advancedLinkImceBrowser){
		advancedLinkImceBrowser.close();
	}
	advancedLinkImceBrowser = window.open('/imce?app=advancedLink|imceload@advancedLinkImceLoad', 'advancedLinkImceBrowser', 'width=760,height=560,resizable=1,status=0,location=0,menubar=0,titlebar=0,left=100,top=100');

	return false;
}

(function ($) {
	Drupal.behaviors.advancedLink = {
		attach: function(context){
			var links = $('.advanced_link_imce a');
			$(links).each(function(i, e){
				$(e).click(function(){
					var field = $(this).attr('data-target');
					openImce(field);

					return false;
				});
			});
		}
	};
})(jQuery);